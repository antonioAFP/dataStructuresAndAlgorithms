#ifndef AVLNODE_H
#define AVLNODE_H


class AvlNode
{
public:
  AvlNode();
  AvlNode(int value, int height_val = 1,
             AvlNode *left = nullptr, AvlNode *rigth = nullptr);

  int data;
  int height;
  AvlNode *left;
  AvlNode *rigth;
};

#endif // AVLNODE_H
