#ifndef SINGLENODE_H
#define SINGLENODE_H


class SingleNode
{
public:
  SingleNode();
  SingleNode(int newValue, SingleNode* newNext = 0);

  int getData();
  void setData(int newValue);

  SingleNode *getNext();
  void setNext(SingleNode *newNext);

protected:
  int data;
  SingleNode *next;
};

#endif // SINGLENODE_H
