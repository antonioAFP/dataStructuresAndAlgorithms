#include "SingleList2.h"
#include <iostream>

using namespace std;

template <class T>
SingleList2<T>::SingleList2()
{
  first = nullptr;
  current = nullptr;
}

template <class T>
void SingleList2<T>::add(T data, SingleNode2<T> *next){
  SingleNode2<T> *node = new SingleNode2<T>(data, next);

  if(!first){
      first = node;
      current = node;
    }else{
      current->setNext(node);
      current = node;
    }
}

template <class T>
void SingleList2<T>::display(){
  SingleNode2<T> *node = first;
  while (node) {
      cout << " " << node->getData();
      node = node->getNext();
    }
  cout << endl;
}

//template class SingleList2<int>;
//template class SingleList2<double>;

