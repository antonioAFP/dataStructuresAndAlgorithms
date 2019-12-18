#include "SingleNode.h"

SingleNode::SingleNode()
{
  data = 0;
  next = nullptr;
}

SingleNode::SingleNode(int newValue, SingleNode* newNext){
  data = newValue;
  next = newNext;
}
