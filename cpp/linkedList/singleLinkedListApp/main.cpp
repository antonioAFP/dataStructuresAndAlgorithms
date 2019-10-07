#include <QCoreApplication>
#include <QDebug>

#include "Lists.h"
#include "SingleList.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  qDebug() << "Hello Darkness, my old friend :D";

  Lists list;
  SingleList singleList;

  singleList.add(0);
  singleList.add(1);
  singleList.add(2);
  singleList.add(3);
  singleList.display();

  qDebug() << "Good bye";


  return a.exec();
}
