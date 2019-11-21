#ifndef STACK_H
#define STACK_H

class SingleNode;

class Stack
{
public:
  Stack();

  void display();
  void push(int value);
  int pop();
  int peek(int index);
  int stackTop();
  bool isEmpty();
  bool isFull();

private:
  SingleNode *top;

};

#endif // STACK_H
