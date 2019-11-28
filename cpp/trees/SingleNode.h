#ifndef SINGLENODE_H
#define SINGLENODE_H

class BinaryNode;

class SingleNode
{
public:
  SingleNode();
  SingleNode(BinaryNode *newValue, SingleNode* newNext = nullptr);

  BinaryNode *data;
  SingleNode *next;
};

#endif // SINGLENODE_H
