#ifndef AVLSINGLENODE_H
#define AVLSINGLENODE_H

class AvlNode;

class AvlSingleNode
{
public:
  AvlSingleNode();
  AvlSingleNode(AvlNode *newValue, AvlSingleNode* newNext = nullptr);

  AvlNode *data;
  AvlSingleNode *next;
};

#endif // AVLSINGLENODE_H
