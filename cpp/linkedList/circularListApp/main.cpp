#include <QCoreApplication>

#include "CircuarList.h"
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  CircuarList list;
  list.insert(0,0);
  list.insert(0,1);
  list.insert(1,2);
  list.insert(1,3);
  list.display();
  qDebug() << "Delete index 2:";
  list.deleteNode(2);
  list.display();

  return a.exec();
}
