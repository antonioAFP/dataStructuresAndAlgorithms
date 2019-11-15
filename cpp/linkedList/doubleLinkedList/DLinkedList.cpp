#include "DLinkedList.h"

#include <iostream>
#include "DLinkedNode.h"

using namespace std;


DLinkedList::DLinkedList()
{
  first = nullptr;
  last = nullptr;
}

void DLinkedList::display(){
  DLinkedNode *p =first;
  while (p) {
      cout << p->data << " ";
      p = p->next;
    }
  cout << endl;
}

int DLinkedList::length(){
  DLinkedNode *p =first;
  int count = 0;
  while (p) {
      count++;
      p = p->next;
    }
  return count;
}

void DLinkedList::insert(int index, int value){
  DLinkedNode *p = first;

  if(index < 0 || index > length())
    return;

  DLinkedNode *newNode = new DLinkedNode(value);

  if(!length()){
      first = newNode;
      last = newNode;
      return;
    }

  if(index == 0){
      newNode->previous = nullptr;
      newNode->next = first;
      first->previous = newNode;
      first = newNode;
    }else {
      for (int i = 0;i < index - 1;i++)
        p = p->next;

      newNode->previous = p;
      newNode->next = p->next;

      if(p->next)
        p->next->previous = newNode;

      p->next = newNode;
    }
}

int DLinkedList::deleteNode(int index){
  DLinkedNode *p = first;
  int x = -1;

  if(!p)
    return x;

  if(index < 1 || index > length())
    return x;

  if(index == 1){
      first = first->next;
      if(first)
        first->previous = nullptr;

      x = p->data;
      delete p;
    }else {
      for (int i = 0;i < index - 1;i++) {
          p = p->next;
        }
      p->previous->next = p->next;
      if(p->next)
        p->next->previous = p->previous;

      x = p->data;

      delete p;
    }
}

void DLinkedList::reverse(){
  DLinkedNode *p = first;
  DLinkedNode *tmp;

  while (p) {
      tmp = p->next;
      p->next = p->previous;
      p->previous = tmp;
      p = p->previous;
      if(p && p->next == nullptr)
        first = p;
    }
}
