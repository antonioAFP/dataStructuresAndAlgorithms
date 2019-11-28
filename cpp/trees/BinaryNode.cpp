#include "BinaryNode.h"

BinaryNode::BinaryNode()
{
  data = -1;
  parent = nullptr;
  left = nullptr;
  rigth = nullptr;
}

BinaryNode::BinaryNode(int value, BinaryNode *parent,
                        BinaryNode *left, BinaryNode *rigth){
  this->data = value;
  this->parent = parent;
  this->left = left;
  this->rigth = rigth;
}
