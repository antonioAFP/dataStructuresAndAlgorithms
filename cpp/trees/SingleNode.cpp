#include "SingleNode.h"
#include "BinaryNode.h"

SingleNode::SingleNode()
{
  data = nullptr;
  next = nullptr;
}

SingleNode::SingleNode(BinaryNode *newValue, SingleNode* newNext){
  data = newValue;
  next = newNext;
}

