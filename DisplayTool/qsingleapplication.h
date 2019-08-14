#ifndef QSINGLEAPPLICATION_H
#define QSINGLEAPPLICATION_H

#include <QApplication>
#include <QSharedMemory>

class  QSingleApplication : public QApplication
{
	Q_OBJECT

public:
	QSingleApplication(int &argc, char *argv[], const QString uniqueKey);

	virtual ~QSingleApplication();
public:
	bool isRunning();
	bool sendMessage(const QString &message);

public slots:
	void checkForMessage();

signals:
	void messageAvailable(QString message);

private:
	bool _isRunning;
	QSharedMemory m_sharedMemory;
};

#endif // QSINGLEAPPLICATION_H
