#include "displaytool.h"
#include <QtWidgets/QApplication>
#include "QFixMainWindow.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QString strPlugins = QCoreApplication::applicationDirPath() + "/plugins";
	QCoreApplication::addLibraryPath(strPlugins);

	//DisplayTool w;
	QFixMainWindow w;
	w.ShowHomePage();
	return a.exec();
}
