#include "displaytool.h"
#include <QtWidgets/QApplication>
#include "QFixMainWindow.h"
#include "qsingleapplication.h"
#include "QSettings"


#define REG_RUN "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run"

void setAutoStart(bool is_auto_start)
{
	QString application_name = QApplication::applicationName();
	QString application_path = QApplication::applicationFilePath();
	application_path = application_path.replace("/", "\\");

	QSettings settings(REG_RUN, QSettings::NativeFormat); 
	if(is_auto_start)
	{
		//QString application_path = QApplication::applicationFilePath();
		QVariant varPath = settings.value(application_name, NULL);
		QString strStartPath = varPath.toString();

		if( 0 != strStartPath.compare(application_path))
		{
			settings.setValue(application_name, application_path);
		}
	}
}

int main(int argc, char *argv[])
{
	QSingleApplication a(argc, argv, "FF2A5066-501F-4A22-9349-706A5F537361");
	if (a.isRunning())
	{
		return 0;
	}

	QString strPlugins = QCoreApplication::applicationDirPath() + "/plugins";
	QCoreApplication::addLibraryPath(strPlugins);

	setAutoStart(true);
	//DisplayTool w;
	QFixMainWindow w;
	w.ShowHomePage();
	return a.exec();
}
