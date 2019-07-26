/*
  Static array lentgh with C language.
  Implements basic functions for an
  array Abstract Data Type (ADT)
    - display
    - append
    - insert
    - delete (del)
    - swap
    - linearSearch
    - binarySearch
    - get
    - set
    - max
    - min
    - avg
    - sum
    - reverse
    - insertSort
    - isSort


*/

#include <stdio.h>
#include <stdlib.h>

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

int get(struct array arr, int index){
  if(index >= 0 && index < arr.length)
    return arr.arr[index];

  return -1;
}

int set(struct array *arr, int index, int x){
  if(index >= 0 && index < arr->length)
    arr->arr[index] = x;
}

int max(struct array arr){
  int max = arr.arr[0];
  int i = 0;

  for(i = 1; i < arr.length; i++){
      if(arr.arr[i] > max)
        max = arr.arr[i];
    }
  return max;
}

int min(struct array arr){
  int min = arr.arr[0];
  int i = 0;

  for(i = 1; i < arr.length; i++){
      if(arr.arr[i] < min)
        min = arr.arr[i];
    }
  return min;
}

int sum(struct array arr){
  int i;
  int s = 0;

  for(i = 0; i < arr.length; i++)
    s += arr.arr[i];

  return s;
}

float avg(struct array arr){
  return (float)sum(arr) / arr.length;
}

void reverse(struct array *arr){
  int i, j;

  for(i = 0, j = arr->length - 1; i < j; i++, j--){
      swap(&arr->arr[i], &arr->arr[j]);
    }
}

void insertSort(struct array *arr, int x){
  int i = arr->length - 1;

  if(arr->length == arr->size)
    return;

  while(i >= 0 && arr->arr[i] > x){
      arr->arr[i + 1] = arr->arr[i];
      i--;
    }

  arr->arr[i + 1] = x;
  arr->length++;
}

int isSorted(struct array arr){
  int i;

  for(i = 0; i < arr.length; i++){
      if(arr.arr[i] > arr.arr[i + 1])
        return 0;
    }

  return 1;
}


/* Negative values to the left side,
 * Positive values to the rigth side */
void reArrenge(struct array *arr){
  int i, j;
  i = 0;
  j = arr->length - 1;

  while(i < j){
      while(arr->arr[i] < 0)
        i++;
      while(arr->arr[i] >= 0)
        j--;
      if(i < j)
        swap(&arr->arr[i], &arr->arr[j]);
    }
}

/*
 * merge 2 ordered arrays
*/
struct array * merge(struct array *arr1, struct array *arr2){
  int i = 0;
  int j = 0;
  int k = 0;

  struct array *arr3 = (struct array *)malloc(sizeof (struct array));

  while(i < arr1->length && j < arr2->length){
      if(arr1->arr[i] < arr2->arr[j])
        arr3->arr[k++] = arr1->arr[i++];
      else
        arr3->arr[k++] = arr2->arr[j++];
    }

  for(;i < arr1->length; i++)
    arr3->arr[k++] = arr1->arr[i];
  for(;j < arr2->length; j++)
    arr3->arr[k++] = arr2->arr[j];

  arr3->length = arr1->length + arr2->length;
  arr3->size = 10;

  return arr3;
}

int main(){
  struct array arr = {{2, 3, 4, 5, 6}, 10, 5};

  printf("%d", binarySearch(arr, 4));
  display(arr);

  return 0;
}
