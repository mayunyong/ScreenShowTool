
#include "qsingleapplication.h"
#include <QTimer>
#include <QByteArray>

QSingleApplication::QSingleApplication(int &argc, char *argv[], const QString uniqueKey)
	: QApplication(argc, argv)
{
	m_sharedMemory.setKey(uniqueKey);
	if (m_sharedMemory.attach()){
		_isRunning = true;
	} else {
		_isRunning = false;
		// attach data to shared memory.
		QByteArray byteArray("0"); // default value to note that n message is available.
		if (!m_sharedMemory.create(byteArray.size())) {
			return;
		}
		m_sharedMemory.lock();
		char *to = (char*)m_sharedMemory.data();
		const char *from = byteArray.data();
		memcpy(to, from, qMin(m_sharedMemory.size(), byteArray.size()));
		m_sharedMemory.unlock();

		// start checking for messages of other instances.
		QTimer *timer = new QTimer(this);
		connect(timer, SIGNAL(timeout()), this, SLOT(checkForMessage()));
		timer->start(1000);
	}
}

QSingleApplication::~QSingleApplication()
{

}

void QSingleApplication::checkForMessage()
{
	m_sharedMemory.lock();
	QByteArray byteArray = QByteArray((char*)m_sharedMemory.constData(), m_sharedMemory.size());
	m_sharedMemory.unlock();
	if (byteArray.left(1) == "0")
		return;
	byteArray.remove(0, 1);
	QString message = QString::fromUtf8(byteArray.constData());
	emit messageAvailable(message);

	// remove message from shared memory.
	byteArray = "0";
	m_sharedMemory.lock();
	char *to = (char*)m_sharedMemory.data();
	const char *from = byteArray.data();
	memcpy(to, from, qMin(m_sharedMemory.size(), byteArray.size()));
	m_sharedMemory.unlock();
}

// public functions.
bool QSingleApplication::isRunning()
{
	return _isRunning;
}

bool QSingleApplication::sendMessage(const QString &message)
{
	if (!_isRunning)
		return false;

	QByteArray byteArray("1");
	byteArray.append(message.toUtf8());
	byteArray.append('/0'); // < should be as char here, not a string!
	m_sharedMemory.lock();
	char *to = (char*)m_sharedMemory.data();
	const char *from = byteArray.data();
	memcpy(to, from, qMin(m_sharedMemory.size(), byteArray.size()));
	m_sharedMemory.unlock();
	return true;
}
