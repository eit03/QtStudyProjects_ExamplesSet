#include <QCoreApplication>
#include "Object.h"

int main(int argc, char *argv[])
{
	QCoreApplication a(argc, argv);

	Object obj;
	obj.objectName();
	obj.setAge(1);
	obj.setName("Prove I am me!");

	return a.exec();
}
