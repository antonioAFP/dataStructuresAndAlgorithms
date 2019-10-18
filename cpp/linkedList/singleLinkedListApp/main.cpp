#include <QCoreApplication>
#include <QDebug>

//#include "Lists.h"
#include "SingleList.h"
//#include "SingleList2.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  qDebug() << "Hello Darkness, my old friend :D";

  //Lists list;
  SingleList singleList;
  //SingleList2<int> singleList2;

  singleList.add(0);
  singleList.add(1);
  singleList.add(2);
  singleList.add(3);
  singleList.display();
  singleList.display();
  singleList.displayReverse(singleList.getFirst());

  qDebug() << "Count: " << singleList.count();
  qDebug() << "Count: " << singleList.count(singleList.getFirst());
  qDebug() << "Sum: " << singleList.sum(singleList.getFirst());
  qDebug() << "Max: " << singleList.max(singleList.getFirst());

  qDebug() << "Good bye";


  return a.exec();
}
