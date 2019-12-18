#ifndef SINGLENODE_H
#define SINGLENODE_H


class SingleNode
{
public:
  SingleNode();
  SingleNode(int newValue, SingleNode* newNext = nullptr);

  int data;
  SingleNode *next;
};

#endif // SINGLENODE_H
