#ifndef SINGLELIST2_H
#define SINGLELIST2_H


#include "lists_global.h"
#include "SingleNode2.h"

/*
  Template class. It compiles but it can't be instantiated.
  Linker or compiler configuration needs to be done first.
*/


template <class T>
class LISTSSHARED_EXPORT SingleList2
{
public:
  SingleList2<T>();

  void add(T data, SingleNode2<T> *next = 0);
  void display();

private:
  SingleNode2<T> *first;
  SingleNode2<T> *current;
};

//typedef SingleList2<int> IntSingleList2;
//typedef SingleList2<double> DoubleSingleList2;
//typedef SingleNode2<std::string> StringStack;


#endif // SINGLELIST2_H
