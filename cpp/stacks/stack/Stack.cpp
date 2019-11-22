#include "Stack.h"
#include <iostream>
#include "SingleNode.h"

using namespace std;

Stack::Stack()
{
  top = nullptr;
}

void Stack::display(){
  SingleNode *node = top;
  while (node) {
      cout << " " << node->data;
      node = node->next;
    }
  cout << endl;
}

void Stack::push(int value){
  SingleNode *p = new SingleNode(value);

  if(!p){
      cout << "Stack Overflow";
    }else {
      p->next = top;
      top = p;
    }
}

int Stack::pop(){
  int x = -1;
  SingleNode *p = nullptr;

  if(!top){
      cout << "Stack is empty";
    }else {
      p = top;
      top = top->next;
      x = p->data;
      delete p;
    }

  return x;
}

int Stack::peek(int index){
  SingleNode *p = top;

  for (int i = 0;p != nullptr && i < index - 1;i++) {
      p = p->next;
    }

  if(p != nullptr)
    return p->data;
  else
    return -1;
}

int Stack::stackTop(){
  if(top)
    return top->data;
  else
    return -1;
}

bool Stack::isEmpty(){
  return top ? false : true;
}

bool Stack::isFull(){
  SingleNode *p = new SingleNode(1);

  bool full = p ? false : true;

  delete p;
  return full;
}
