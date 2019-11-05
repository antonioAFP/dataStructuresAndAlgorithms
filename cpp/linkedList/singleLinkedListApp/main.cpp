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
  singleList.add(4);
  singleList.display();
  singleList.display();
  singleList.displayReverse(singleList.getFirst());

  qDebug() << "Count: " << singleList.count();
  qDebug() << "Count: " << singleList.count(singleList.getFirst());
  qDebug() << "Sum: " << singleList.sum(singleList.getFirst());
  qDebug() << "Max: " << singleList.max(singleList.getFirst());

  if(singleList.linearSearch(singleList.getFirst(), 3))
    qDebug() << "key exist on list";
  else
    qDebug() << "key doesn´t exists";

  if(singleList.improvedLinearSearch(singleList.getFirst(), 3))
    qDebug() << "key exist on list";
  else
    qDebug() << "key doesn´t exists";

  singleList.displayReverse(singleList.getFirst());

  singleList.insert(0, 5);
  singleList.display();
  singleList.insert(4, 6);
  singleList.display();




  qDebug() << "Good bye";


  return a.exec();
}
