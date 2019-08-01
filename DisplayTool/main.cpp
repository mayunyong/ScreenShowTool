#include "displaytool.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QString strPlugins = QCoreApplication::applicationDirPath() + "/plugins";
	QCoreApplication::addLibraryPath(strPlugins);

	DisplayTool w;
	w.showMaximized();
	return a.exec();
}
