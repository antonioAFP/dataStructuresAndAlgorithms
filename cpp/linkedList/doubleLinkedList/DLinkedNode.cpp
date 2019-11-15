#include "DLinkedNode.h"

DLinkedNode::DLinkedNode()
{

}

DLinkedNode::DLinkedNode(int value, DLinkedNode *prev, DLinkedNode *nex){
  data = value;
  previous = prev;
  next = nex;
}
/*
int DLinkedNode::getData(){
  return data;
}
void DLinkedNode::setData(int value){
  data = value;
}

DLinkedNode *DLinkedNode::getPrevious(){
  return previous;
}

void DLinkedNode::setPrevious(DLinkedNode *newPrev){
  previous = newPrev;
}

DLinkedNode *DLinkedNode::getNext(){
  return next;
}

void DLinkedNode::setNext(DLinkedNode *newNext){
  next = newNext;
}
*/
