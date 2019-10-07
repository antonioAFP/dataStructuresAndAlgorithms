#include "SingleNode.h"

SingleNode::SingleNode()
{
  data = 0;
  next = 0;
}

SingleNode::SingleNode(int newValue, SingleNode* newNext){
  data = newValue;
  next = newNext;
}

int SingleNode::getData(){
  return data;
}

void SingleNode::setData(int newValue){
  data = newValue;
}

SingleNode *SingleNode::getNext(){
  return next;
}

void SingleNode::setNext(SingleNode *newNext){
  next = newNext;
}
