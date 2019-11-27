#ifndef QUEUE_H
#define QUEUE_H

class SingleNode;

class Queue
{
public:
  Queue();

  void display();
  bool isEmpty();
  bool isFull();
  void enqueue(int value);
  int dequeue();

private:
  SingleNode *front;
  SingleNode *rear;
};

#endif // QUEUE_H
