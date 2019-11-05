#include "SingleList.h"
#include <iostream>

using namespace std;

SingleList::SingleList()
{
  first = nullptr;
  current = nullptr;
}

SingleNode *SingleList::getFirst() const{
  return first;
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

void SingleList::display(SingleNode *node){
  if(node != nullptr){
      cout << node->getData() << " ";
      display(node->getNext());
    }
  cout << endl;
}

void SingleList::displayReverse(SingleNode *node){
  if(node != nullptr){
      displayReverse(node->getNext());
      cout << node->getData() << " ";
    }
}

int SingleList::count(){
  SingleNode *node = first;
  int counter = 0;
  while (node) {
      counter++;
      node = node->getNext();
    }
  return counter;
}

int SingleList::count(SingleNode *node){
  if(node == nullptr)
    return 0;
  return count(node->getNext()) + 1;
}

int SingleList::sum(SingleNode *node){
  SingleNode *tmpNode = node;
  int result = 0;
  while (tmpNode) {
      result += tmpNode->getData();
      tmpNode = tmpNode->getNext();
    }
  return result;
}

int SingleList::max(SingleNode *node){
  SingleNode *tmpNode = node;
  int max = -32768;
  while (tmpNode) {
      if(tmpNode->getData() > max)
        max = tmpNode->getData();

      tmpNode = tmpNode->getNext();
    }
  return max;
}

SingleNode *SingleList::linearSearch(SingleNode *p, int key){
  while(p){
      if(p->getData() == key)
        return p;
      p = p->getNext();
    }
  return nullptr;
}

SingleNode *SingleList::improvedLinearSearch(SingleNode *p, int key){
  SingleNode *q = nullptr;

  while(p){
      if(p->getData() == key){
          q->setNext(p->getNext());
          p->setNext(first);
          first = p;
          return p;
        }
      q = p;
      p = p->getNext();
    }
  return nullptr;
}

void SingleList::insert(int pos, int value){
  SingleNode *t, *p;

  if(pos == 0){
      t = new SingleNode(value);
      t->setNext(first);
      first = t;
    }else if(pos > 0){
      p = first;

      for(int i = 0; i < pos -1; i++){
          p = p->getNext();
        }

      if(p){
          t = new SingleNode(value);
          t->setNext(p->getNext());
          p->setNext(t);
        }

    }
}

