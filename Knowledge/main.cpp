#include "knowledge.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Knowledge w;
	w.show();
	return a.exec();
}
