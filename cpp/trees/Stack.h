#ifndef STACK_H
#define STACK_H

class SingleNode;
class BinaryNode;

class Stack
{
public:
  Stack();

  void display();
  void push(BinaryNode *value);
  BinaryNode * pop();
  //int peek(int index);
  BinaryNode * stackTop();
  bool isEmpty();
  bool isFull();

private:
  SingleNode *top;

};

#endif // STACK_H
