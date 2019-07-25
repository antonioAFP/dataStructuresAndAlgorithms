/*
  Static array lentgh with C language.
  Implements basic functions for an
  array Abstract Data Type (ADT)
*/

#include <stdio.h>

struct array{
  int arr[10];
  int size;
  int length;
};

void display(struct array arr){
  int i;

  printf("\nElements are:\n");

  for(i = 0; i < arr.length; i++)
    printf("%d ", arr.arr[i]);
}

void append(struct array *arr, int x){
  if(arr->length < arr->size)
    arr->arr[arr->length++] = x;
}

void insert(struct array *arr, int index, int x){
  int i;

  if(index >= 0 && index <= arr->length){
      for(i = arr->length; i > index; i++)
        arr->arr[i] = arr->arr[i + 1];

      arr->arr[index] = x;
      arr->length++;
    }
}

/*  delete */
int del(struct array *arr, int index){
  int x = 0;
  int i;

  if(index >= 0 && index < arr->length){
      x = arr->arr[index];
      for(i = index; i < arr->length - 1; i++)
        arr->arr[i] = arr->arr[i + 1];
      arr->length--;
      return x;
    }
  return 0;
}

void swap(int *x, int *y){
  int tmp = *x;

  *x = *y;
  *y = tmp;
}

int linearSearch(struct array *arr, int key){
  int i;

  for(i = 0; i < arr->length; i++){
      if(key == arr->arr[i]){
          swap(&arr->arr[i], &arr->arr[i - 1]);
          return i;
        }
    }

  return -1;
}

/* arr must be previously ordered in asc*/
int binarySearch(struct array arr, int key){
  int low, mid, high;
  low = 0;
  high = arr.length - 1;

  while(low <= high){
      mid = (low + high) / 2;

      if(key == arr.arr[mid])
        return mid;
      else if(key > arr.arr[mid]) //right side
        low = mid + 1;
      else  //left side
        high = mid - 1;
    }

  return -1;
}

int main(){
  struct array arr = {{2, 3, 4, 5, 6}, 10, 5};

  printf("%d", binarySearch(arr, 4));
  display(arr);

  return 0;
}
