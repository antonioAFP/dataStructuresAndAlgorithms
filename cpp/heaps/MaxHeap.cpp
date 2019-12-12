#include "MaxHeap.h"

MaxHeap::MaxHeap(int *array, int size)
{
  //heap = new int[size];
  for (int i = 1;i < size; i++) {
      insert(array, i);
    }
}

void MaxHeap::insert(int *array, int n){
  int tmp = array[n];
  int i = n;

  while (i > 1 && tmp > array[i / 2]) {
      array[i] = array[i / 2];
      i = i / 2;
    }

  array[i] = tmp;
}

void MaxHeap::deleteItem(int *array, int n){
  int x, i, j;

  x = array[n];
  array[0] = array[n];

  i = 1;
  j = 2 * i;

  while(j < n - 1){
      if(array[j + 1] > array[j])
        j++;
      if(array[i] < array[j]){
          int tmp = array[i];
          array[i] = array[j];
          array[j] = tmp;
          i = j;
          j = 2 * j;
        }else
          break;
    }

  array[n] = x;
}
