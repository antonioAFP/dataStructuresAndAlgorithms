#include <QCoreApplication>

#include "DLinkedList.h"
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  DLinkedList list;
  list.insert(0, 0);
  list.insert(0, 1);
  list.insert(0, 2);
  list.insert(0, 3);
  list.insert(2, 4);
  list.display();

  qDebug() << "Delete index 2";
  list.deleteNode(2);
  list.display();
  qDebug() << "Reverse list:";
  list.reverse();
  list.display();

  return a.exec();
}
