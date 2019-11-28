#ifndef BINARYNODE_H
#define BINARYNODE_H


class BinaryNode
{
public:
  BinaryNode();
  BinaryNode(int value, BinaryNode *parent = nullptr,
             BinaryNode *left = nullptr, BinaryNode *rigth = nullptr);

  int data;
  BinaryNode *parent;
  BinaryNode *left;
  BinaryNode *rigth;
};

#endif // BINARYNODE_H
