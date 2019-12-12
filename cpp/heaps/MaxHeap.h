#ifndef MAXHEAP_H
#define MAXHEAP_H


class MaxHeap
{
public:
  MaxHeap(int *array, int size);
  void insert(int *array, int size);
  void deleteItem(int *array, int n);

  int size;
  int *heap;
};

#endif // MAXHEAP_H
