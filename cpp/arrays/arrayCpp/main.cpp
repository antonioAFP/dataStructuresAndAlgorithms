/*
  Static array lentgh with C++ language.
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
#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

class array{
private:
  int *arr;
  int size;
  int length;
  void swap(int *x, int *y);

public:
  array(){
    size = 10;
    length = 0;
    arr = new int[size];
  }

  array(int sz){
    size = sz;
    length = 0;
    arr = new int[sz];
  }

  ~array(){
    delete []arr;
  }


  void display();
  void append(int x);
  void insert(int index, int x);
  int del(int index);

  int linearSearch(int key);
  int binarySearch(int key);
  int get(int index);
  int set(int index, int x);
  int max();
  int min();
  int sum();
  float avg();
  void reverse();
  void insertSort(int x);
  int isSorted();
  void reArrenge();
  array * merge(array arr2);
  array * unionArr(array arr2);
  array * intersection(array arr2);
  array * difference(array arr2);

};

void array::display(){
  int i;

  printf("\nElements are:\n");

  for(i = 0; i < length; i++)
    printf("%d ", arr[i]);
}

void array::append(int x){
  if(length < size)
    arr[length++] = x;
}

void array::insert(int index, int x){
  int i;

  if(index >= 0 && index <= length){
      for(i = length; i > index; i--)
        arr[i] = arr[i - 1];

      arr[index] = x;
      length++;
    }
}

/*  delete */
int array::del(int index){
  int x = 0;
  int i;

  if(index >= 0 && index < length){
      x = arr[index];
      for(i = index; i < length - 1; i++)
        arr[i] = arr[i + 1];
      length--;
      return x;
    }
  return 0;
}

void array::swap(int *x, int *y){
  int tmp = *x;

  *x = *y;
  *y = tmp;
}

int array::linearSearch(int key){
  int i;

  for(i = 0; i < length; i++){
      if(key == arr[i]){
          swap(&arr[i], &arr[i - 1]);
          return i;
        }
    }

  return -1;
}

/* arr must be previously ordered in asc*/
int array::binarySearch(int key){
  int low, mid, high;
  low = 0;
  high = length - 1;

  while(low <= high){
      mid = (low + high) / 2;

      if(key == arr[mid])
        return mid;
      else if(key > arr[mid]) //right side
        low = mid + 1;
      else  //left side
        high = mid - 1;
    }

  return -1;
}

int array::get(int index){
  if(index >= 0 && index < length)
    return arr[index];

  return -1;
}

int array::set(int index, int x){
  if(index >= 0 && index < length)
    arr[index] = x;
}

int array::max(){
  int max = arr[0];
  int i = 0;

  for(i = 1; i < length; i++){
      if(arr[i] > max)
        max = arr[i];
    }
  return max;
}

int array::min(){
  int min = arr[0];
  int i = 0;

  for(i = 1; i < length; i++){
      if(arr[i] < min)
        min = arr[i];
    }
  return min;
}

int array::sum(){
  int i;
  int s = 0;

  for(i = 0; i < length; i++)
    s += arr[i];

  return s;
}

float array::avg(){
  return (float)sum() / length;
}

void array::reverse(){
  int i, j;

  for(i = 0, j = length - 1; i < j; i++, j--){
      swap(&arr[i], &arr[j]);
    }
}

void array::insertSort(int x){
  int i = length - 1;

  if(length == size)
    return;

  while(i >= 0 && arr[i] > x){
      arr[i + 1] = arr[i];
      i--;
    }

  arr[i + 1] = x;
  length++;
}

int array::isSorted(){
  int i;

  for(i = 0; i < length; i++){
      if(arr[i] > arr[i + 1])
        return 0;
    }

  return 1;
}


/* Negative values to the left side,
 * Positive values to the rigth side */
void array::reArrenge(){
  int i, j;
  i = 0;
  j = length - 1;

  while(i < j){
      while(arr[i] < 0)
        i++;
      while(arr[i] >= 0)
        j--;
      if(i < j)
        swap(&arr[i], &arr[j]);
    }
}

/*
 * merge 2 ordered arrays
*/
array * array::merge(array arr2){
  int i = 0;
  int j = 0;
  int k = 0;

  array *arr3 = new array(length + arr2.length);

  while(i < length && j < arr2.length){
      if(arr[i] < arr2.arr[j])
        arr3->arr[k++] = arr[i++];
      else
        arr3->arr[k++] = arr2.arr[j++];
    }

  for(;i < length; i++)
    arr3->arr[k++] = arr[i];
  for(;j < arr2.length; j++)
    arr3->arr[k++] = arr2.arr[j];

  arr3->length = length + arr2.length;
  return arr3;
}

/*
 * union 2 arrays without duplicates
*/
array *array::unionArr(array arr2){
  int i, j, k;
  i = j = k = 0;

  array *arr3 = new array(length + arr2.length);

  while(i < length && j < arr2.length){
      if(arr[i] < arr2.arr[j])
        arr3->arr[k++] = arr[i++];
      else if(arr2.arr[j] < arr[i]){
        arr3->arr[k++] = arr2.arr[j++];
      }else{
        arr3->arr[k++] = arr[i++];
        j++;
        }
    }

  for(; i < length; i++)
    arr3->arr[k++] = arr[i];
  for(; j < arr2.length; j++)
    arr3->arr[k++] = arr2.arr[j];

  arr3->length = k;
  return arr3;
}


/*
 * only copies the intersectiong elements (only the same value elements)
*/
array * array::intersection(array arr2){
  int i, j, k;
  i = j = k = 0;

  array *arr3 = new array(length + arr2.length);

  while(i < length && j < arr2.length){
      if(arr[i] < arr2.arr[j])
        i++;
      else if(arr2.arr[j] < arr[i]){
        j++;
      }else if(arr[i] == arr2.arr[j]){
        arr3->arr[k++] = arr[i++];
        j++;
        }
    }

  arr3->length = k;
  return arr3;
}

/*
 * only different values
*/
array * array::difference( array arr2){
  int i, j, k;
  i = j = k = 0;

  array *arr3 = new array(length + arr2.length);

  while(i < length && j < arr2.length){
      if(arr[i] < arr2.arr[j])
        arr3->arr[k++] = arr[i++];
      else if(arr2.arr[j] < arr[i]){
        j++;
      }else{
        i++;
        j++;
        }
    }

  for(; i < length; i++)
    arr3->arr[k++] = arr[i];


  arr3->length = k;
  arr3->size = 10;
  return arr3;
}

int main(){
  int choice;
  int x, index, size;

  printf("Enter size of array:");
  scanf("%d", &size);

  array arr1(size);

  do{
    printf("\n-- Menu --\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
      case 1:
        printf("Enter an element and index: ");
        scanf("%d%d", &x, &index);
        arr1.insert(index, x);
        arr1.display();
        break;
      case 2:
        printf("Enter index to delete: ");
        scanf("%d", &index);
        x = arr1.del(index);
        printf("Deleted element is: %d", x);
        break;
      case 3:
        printf("Enter element to search: ");
        scanf("%d", &x);
        index = arr1.linearSearch(x);
        printf("element idex: %d", index);
        break;
      case 4:
        printf("Sum is: %d\n", arr1.sum() );
        break;
      case 5:
        arr1.display();
        break;
      }
    }while(choice < 6);

  return 0;
}
