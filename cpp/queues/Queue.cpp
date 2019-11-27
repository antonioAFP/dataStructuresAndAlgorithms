#include "Queue.h"
#include <iostream>
#include "SingleNode.h"

using namespace std;

Queue::Queue()
{
  front = nullptr;
  rear = nullptr;
}

void Queue::display(){
  SingleNode *p = front;

  while (p) {
      cout << p->data << " ";
      p = p->next;
    }
  cout << endl;
}

bool Queue::isEmpty(){
  if(!front)
    return true;
  return false;
}

bool Queue::isFull(){
  SingleNode *t = new SingleNode(1);

  bool full = t ? false : true;

  if(t)
    delete t;

  return full;
}

void Queue::enqueue(int value){
  SingleNode *t = new SingleNode(value);

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

int Queue::dequeue(){
  int x = -1;
  SingleNode *p = nullptr;

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
