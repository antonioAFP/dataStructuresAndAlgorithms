#include <QCoreApplication>

#include "CircuarList.h"
#include <QDebug>

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  CircuarList list;
  list.insert(0,0);
  list.insert(0,1);
  list.display();

  return a.exec();
}
