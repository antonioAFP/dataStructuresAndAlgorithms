#ifndef AVLQUEUE_H
#define AVLQUEUE_H

class AvlNode;
class AvlSingleNode;

class AvlQueue
{
public:
  AvlQueue();

  void display();
  bool isEmpty();
  bool isFull();
  void enqueue(AvlNode *value);
  AvlNode * dequeue();

private:
  AvlSingleNode *front;
  AvlSingleNode *rear;
};

#endif // AVLQUEUE_H
