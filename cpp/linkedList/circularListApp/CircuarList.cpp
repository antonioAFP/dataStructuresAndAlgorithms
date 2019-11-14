#include "CircuarList.h"
#include <iostream>

using namespace std;

CircuarList::CircuarList()
{
  head = nullptr;
}

CircuarList::~CircuarList(){
  SingleNode *p = head;

  if(!p)
    return;

  do{
      SingleNode *tmp = p->getNext();
      delete tmp;
      p = p->getNext();
    }while(p != head);
}

void CircuarList::display(){
  SingleNode *p = head;

  if(!p)
    return;

  do{
      cout << p->getData() << " ";
      p = p->getNext();
    }while(p != head);

  cout << endl;
}

int CircuarList::length(){
  int len = 0;
  SingleNode *p = head;

  if(!p)
    return 0;

  do{
      len++;
      p = p->getNext();
    }while(p != head);

  return len;
}

void CircuarList::insert(int pos, int value){
  SingleNode *t = nullptr;
  SingleNode *p = nullptr;

  if(pos < 0 || pos > length())
    return;

  if(pos == 0){
      t = new SingleNode(value);

      if(head == nullptr){
          head = t;
          head->setNext(head);
        }else {
          p = head; // ?
          while (p->getNext() != head) {
              p = p->getNext();
            }
          p->setNext(t);
          t->setNext(head);
          head = t;
        }
    }else {
      p = head;

      for (int i = 0;i < pos - 1;i++) {
          p = p->getNext();
        }

      t = new SingleNode(value);
      t->setNext(p->getNext());
      p->setNext(t);
    }
}

int CircuarList::deleteNode(int index){
  SingleNode *p;
  SingleNode *q;
  int x = -1;

  if(index < 0 || index > length())
    return -1;

  if(index == 1){
      p = head;
      while(p->getNext() != head){
          p = p->getNext();
        }
      x = head->getData();

      if(p == head){
          delete head;
          head = nullptr;
        }else {
          p->setNext(head->getNext());
          delete head;
          head = p->getNext();
        }
    }else {
      p = head;
      for (int i = 0;i < index -2; i++) {
          p = p->getNext();
        }
      q = p->getNext();
      p->setNext(q->getNext());
      x = q->getData();
      delete q;
    }

  return x;
}
