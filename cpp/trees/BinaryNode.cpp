#include "BinaryNode.h"

BinaryNode::BinaryNode()
{
  data = -1;
  left = nullptr;
  rigth = nullptr;
}

BinaryNode::BinaryNode(int value,
                        BinaryNode *left, BinaryNode *rigth){
  this->data = value;
  this->left = left;
  this->rigth = rigth;
}
