#ifndef SINGLELIST_H
#define SINGLELIST_H

#include "SingleNode.h"

class SingleList
{
public:
  SingleList();
  ~SingleList();

  SingleNode *getFirst() const;
  void add(int data, SingleNode *next = 0);
  void display();
  void display(SingleNode *p);
  void displayReverse(SingleNode *p);
  int count();
  int count(SingleNode *p);
  int sum(SingleNode *p);
  int max(SingleNode *p);
  SingleNode *linearSearch(SingleNode *p, int key);
  SingleNode *improvedLinearSearch(SingleNode *p, int key);
  void insert(int pos, int value);
  void insertLast(int value);
  void sortedInsert(int value);
  int deleteNode(int index);
  bool isSorted();
  void removeDuplicates();
  void reverse();
  void reverseSlicing();
  void concat(SingleNode *list);
  int isLoop(SingleNode *f);




private:
  SingleNode *first, *last;
  SingleNode *current;
};

#endif // SINGLELIST_H
