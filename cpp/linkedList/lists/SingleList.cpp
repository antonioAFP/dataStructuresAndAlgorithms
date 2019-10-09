#include "SingleList.h"
#include <iostream>

using namespace std;

SingleList::SingleList()
{
  first = nullptr;
  current = nullptr;
}

void SingleList::add(int data, SingleNode *next){
  SingleNode *node = new SingleNode(data, next);

  if(!first){
      first = node;
      current = node;
    }else{
      current->setNext(node);
      current = node;
    }
}

void SingleList::display(){
  SingleNode *node = first;
  while (node) {
      cout << " " << node->getData();
      node = node->getNext();
    }
  cout << endl;
}
