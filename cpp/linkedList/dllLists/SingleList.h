#ifndef SINGLELIST_H
#define SINGLELIST_H

#include "lists_global.h"
#include "SingleNode.h"

class LISTSSHARED_EXPORT SingleList
{
public:
  SingleList();

  void add(int data, SingleNode *next = 0);
  void display();

private:
  SingleNode *first;
  SingleNode *current;
};

#endif // SINGLELIST_H
