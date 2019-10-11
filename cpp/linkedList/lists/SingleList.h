#ifndef SINGLELIST_H
#define SINGLELIST_H

#include "lists_global.h"
#include "SingleNode.h"

class LISTSSHARED_EXPORT SingleList
{
public:
  SingleList();

  SingleNode *getFirst() const;
  void add(int data, SingleNode *next = 0);
  void display();
  void display(SingleNode *p);
  void displayReverse(SingleNode *p);
  int count();
  int count(SingleNode *p);
  int sum(SingleNode *p);

private:
  SingleNode *first;
  SingleNode *current;
};

#endif // SINGLELIST_H
