#include <QCoreApplication>
#include "Queue.h"
#include <iostream>


int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  Queue queue;

  queue.enqueue(0);
  queue.enqueue(1);
  queue.enqueue(2);
  queue.enqueue(3);
  std::cout << "Queue: ";
  queue.display();

  std::cout << "Dequeue: " << queue.dequeue();
  std::cout << "Queue: ";
  queue.display();

  return a.exec();
}
