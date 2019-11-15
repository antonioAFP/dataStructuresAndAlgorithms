#ifndef DLINKEDNODE_H
#define DLINKEDNODE_H


class DLinkedNode
{
public:
  DLinkedNode();
  DLinkedNode(int value, DLinkedNode *prev = nullptr, DLinkedNode *nex = nullptr);

  /*
  int getData();
  void setData(int value);
  DLinkedNode *getPrevious();
  void setPrevious(DLinkedNode *newPrev);
  DLinkedNode *getNext();
  void setNext(DLinkedNode *newNext);
  */
public:
  int data;
  DLinkedNode *previous;
  DLinkedNode *next;
};

#endif // DLINKEDNODE_H


