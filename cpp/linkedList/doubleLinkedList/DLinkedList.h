#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

class DLinkedNode;

class DLinkedList
{
public:
  DLinkedList();

  void display();
  int length();
  void insert(int index, int value);
  int deleteNode(int index);
  void reverse();

private:
  DLinkedNode *first;
  DLinkedNode *last;
};

#endif // DLINKEDLIST_H
