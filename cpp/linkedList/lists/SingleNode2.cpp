#include "SingleNode2.h"

template <class T>
SingleNode2<T>::SingleNode2()
{
  //data = 0;
  next = nullptr;
}

template <class T>
SingleNode2<T>::SingleNode2(T newValue, SingleNode2* newNext){
  data = newValue;
  next = newNext;
}

template <class T>
T SingleNode2<T>::getData(){
  return data;
}

template <class T>
void SingleNode2<T>::setData(T newValue){
  data = newValue;
}

template <class T>
SingleNode2<T> *SingleNode2<T>::getNext(){
  return next;
}

template <class T>
void SingleNode2<T>::setNext(SingleNode2 *newNext){
  next = newNext;
}

//extern template class SingleNode2<int>;
//extern template class SingleNode2<double>;
