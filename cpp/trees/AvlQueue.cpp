#include "AvlQueue.h"
#include <iostream>
#include "AvlSingleNode.h"
#include "AvlNode.h"

using namespace std;


AvlQueue::AvlQueue()
{
  front = nullptr;
  rear = nullptr;
}

void AvlQueue::display(){
  AvlSingleNode *p = front;

  while (p) {
      cout << p->data->data << " ";
      p = p->next;
    }
  cout << endl;
}

bool AvlQueue::isEmpty(){
  if(!front)
    return true;
  return false;
}

bool AvlQueue::isFull(){
  AvlNode *t = new AvlNode(1);

  bool full = t ? false : true;

  if(t)
    delete t;

  return full;
}

void AvlQueue::enqueue(AvlNode *value){
  AvlSingleNode *t = new AvlSingleNode(value);

  if(!t)
    cout << "Queue is full";
  else{
      if(!front){
          front = t;
          rear = t;
        }else {
          rear->next = t;
          rear = t;
        }

    }
}

AvlNode * AvlQueue::dequeue(){
  AvlNode *x = nullptr;
  AvlSingleNode *p = nullptr;

  if(!front)
    cout << "Queue is empty";
  else{
      p = front;
      front = front->next;
      x = p->data;
      delete p;
    }

  return x;
}
