#include "AvlSingleNode.h"
#include "AvlNode.h"

AvlSingleNode::AvlSingleNode()
{
  data = nullptr;
  next = nullptr;
}

AvlSingleNode::AvlSingleNode(AvlNode *newValue, AvlSingleNode* newNext){
  data = newValue;
  next = newNext;
}

