#ifndef CIRCUARLIST_H
#define CIRCUARLIST_H

#include "SingleNode.h"

class CircuarList
{
public:
  CircuarList();
  ~CircuarList();

  void display();
  int length();
  void insert(int pos, int value);
  int deleteNode(int index);

private:
  SingleNode *head;
};

#endif // CIRCUARLIST_H
