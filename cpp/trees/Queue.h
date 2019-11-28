#ifndef QUEUE_H
#define QUEUE_H

class BinaryNode;
class SingleNode;

class Queue
{
public:
  Queue();

  void display();
  bool isEmpty();
  bool isFull();
  void enqueue(BinaryNode *value);
  BinaryNode * dequeue();

private:
  SingleNode *front;
  SingleNode *rear;
};

#endif // QUEUE_H
