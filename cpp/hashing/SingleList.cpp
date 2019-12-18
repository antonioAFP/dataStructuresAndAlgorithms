#include "SingleList.h"
#include <iostream>

using namespace std;

SingleList::SingleList()
{
  first = nullptr;
  last = nullptr;
  current = nullptr;
}

SingleList::~SingleList(){
  SingleNode *node = first;
  while (node) {
      SingleNode *tmp = node->next;
      delete node;
      node = tmp;
    }
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
      current->next = node;
      current = node;
    }
}

void SingleList::display(){
  SingleNode *node = first;
  while (node) {
      cout << " " << node->data;
      node = node->next;
    }
  cout << endl;
}

void SingleList::display(SingleNode *node){
  if(node != nullptr){
      cout << node->data << " ";
      display(node->next);
    }
  cout << endl;
}

void SingleList::displayReverse(SingleNode *node){
  if(node != nullptr){
      displayReverse(node->next);
      cout << node->data << " ";
    }
}

int SingleList::count(){
  SingleNode *node = first;
  int counter = 0;
  while (node) {
      counter++;
      node = node->next;
    }
  return counter;
}

int SingleList::count(SingleNode *node){
  if(node == nullptr)
    return 0;
  return count(node->next) + 1;
}

int SingleList::sum(SingleNode *node){
  SingleNode *tmpNode = node;
  int result = 0;
  while (tmpNode) {
      result += tmpNode->data;
      tmpNode = tmpNode->next;
    }
  return result;
}

int SingleList::max(SingleNode *node){
  SingleNode *tmpNode = node;
  int max = -32768;
  while (tmpNode) {
      if(tmpNode->data > max)
        max = tmpNode->data;

      tmpNode = tmpNode->next;
    }
  return max;
}

SingleNode *SingleList::linearSearch(SingleNode *p, int key){
  while(p){
      if(p->data == key)
        return p;
      p = p->next;
    }
  return nullptr;
}

SingleNode *SingleList::improvedLinearSearch(SingleNode *p, int key){
  SingleNode *q = nullptr;

  while(p){
      if(p->data == key){
          q->next = p->next;
          p->next = first;
          first = p;
          return p;
        }
      q = p;
      p = p->next;
    }
  return nullptr;
}

void SingleList::insert(int pos, int value){
  SingleNode *t, *p;

  if(pos == 0){
      t = new SingleNode(value);
      t->next = first;
      first = t;
    }else if(pos > 0){
      p = first;

      for(int i = 0; i < pos -1; i++){
          p = p->next;
        }

      if(p){
          t = new SingleNode(value);
          t->next = p->next;
          p->next = t;
        }

    }
}

void SingleList::insertLast(int value){
  SingleNode *node = new SingleNode(value);

  if(!first){
      last = node;
      first = node;
    }else{
      last->next = node;
      last = node;
    }
}

void SingleList::sortedInsert(int value){
  SingleNode *p = first;
  SingleNode *q = nullptr;

  SingleNode *node = new SingleNode(value);

  if(!first){
    first = node;
    }else{

      while(p && p->data < value){
          q = p;
          p = p->next;
        }

      if(p == first){
          node->next = first;
          first = node;
        }else{
          node->next = q->next;
          q->next = node;
        }
    }
  last = node;
}

int SingleList::deleteNode(int index){
  SingleNode *q = nullptr;
  SingleNode *p = first;
  int x = -1;

  if(index < 1 || index > count())
    return x;  //out of bounds

  if(index == 1){
    q = first;
    x = q->data;
    first = first->next;
    delete q;
    return x;
    }else{
      for(int i = 0; i < index -1; i++){
          q = p;
          p = p->next;
        }
      q->next = p->next;
      x = p->data;
      delete p;
      return x;
    }
}

bool SingleList::isSorted(){
  int x = -32768; //minimun int value for INT 2 bytes
  SingleNode *p = first;

  while(p){
      if(p->data < x)
        return false;

      x = p->data;
      p = p->next;
    }

  return x;
}

void SingleList::removeDuplicates(){
  SingleNode *p = first;
  SingleNode *q = first->next;

  while (q) {
      if(p->data != q->data){
          p = q;
          q = q->next;
        }else{
          p->next = q->next;
          delete q;
          q = p->next;
        }
    }
}

void SingleList::reverse(){
  SingleNode *p = first;
  int nodes[count()];
  int i = 0;

  while (p) {
      nodes[i] = p->data;
      p = p->next;
      i++;
    }

  p = first;
  i--;

  while (p) {
      p->data = nodes[i--];
      p = p->next;
    }
}

void SingleList::reverseSlicing(){
  SingleNode *p = first;
  SingleNode *q = nullptr;
  SingleNode *r = nullptr;

  while(p){
      r = q;
      q = p;
      p = p->next;
      q->next = r; //reverse link
    }

  first = q;
}

void SingleList::concat(SingleNode *list){
  SingleNode *p = first;
  while(p->next)
    p = p->next;

  p->next = list;
}

int SingleList::isLoop(SingleNode *f){
  SingleNode *p = nullptr;
  SingleNode *q = nullptr;

  p = f;
  q = f;

  do{
      p = p->next;
      q = q->next;
      q = q ? q->next : q;
    }while(p && q && p != q);

  if(p == q)
    return 1;
  else {
      return 0;
    }
}
