#include "AvlNode.h"

AvlNode::AvlNode()
{
  data = -1;
  height = 1;
  left = nullptr;
  rigth = nullptr;
}

AvlNode::AvlNode(int value, int height_val,
                        AvlNode *left, AvlNode *rigth){
  this->data = value;
  this->height = height_val;
  this->left = left;
  this->rigth = rigth;
}
