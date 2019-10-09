#ifndef SINGLENODE2_H
#define SINGLENODE2_H

/*
  Template class. It compiles but it can't be instantiated.
  Linker or compiler configuration needs to be done first.
*/

template <class T>
class SingleNode2
{
public:
  SingleNode2();
  SingleNode2<T>(T newValue, SingleNode2* newNext = 0);

  T getData();
  void setData(T newValue);

  SingleNode2 *getNext();
  void setNext(SingleNode2 *newNext);

protected:
  T data;
  SingleNode2 *next;
};

//typedef SingleNode2<int> IntSingleNode2;
//typedef SingleNode2<double> DoubleSingleNode2;

//extern template class SingleNode2<int>;
//extern template class SingleNode2<double>;

#endif // SINGLENODE2_H
