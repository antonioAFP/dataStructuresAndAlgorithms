#include <QCoreApplication>
#include <iostream>

using namespace std;

void display(int *a, int n){
  for (int i = 0;i < n;i++) {
      cout << a[i] << " ";
    }
  cout << endl;
}


void swap(int *a, int *b){
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

void bubbleSort(int *a, int n){
  int flag = 0;
  for (int i = 0;i < n - 1; i++) {
      flag = 0;
      for(int j = 0; j < n-i-1; j++){
          if(a[j] > a[j + 1]){
              swap(&a[j], &a[j + 1]);
              flag = 1;
            }
        }
      if(flag == 0)
        break;
    }
}

void insertionSort(int *a, int n){
  int j, x;

  for (int i = 1; i < n; i++) {
     j = i - 1;
     x = a[i];
     while (j > -1 && a[j] > x) {
         a[j+1] = a[j];
         j--;
       }
     a[j+1] = x;
    }
}

void selectionSort(int *a, int n){
  int i, j, k;

  for (i = 0;i < n-1;i++) {
      for (j=k=i; j < n;j++) {
          if(a[j] < a[k])
            k = j;
        }
      swap(&a[i], &a[k]);
    }
}

int partition(int *a, int low, int high){
  int pivot = a[low];
  int i = low;
  int j = high;

  do{
      do{
          i++;
        }while (a[i] <= pivot);

      do{
          j--;
        }while(a[j] > pivot);

      if(i<j)
        swap(&a[i], &a[j]);

    }while(i<j);

  swap(&a[low], &a[j]);

  return j;
}

void quickSort(int *a, int low, int high){
  int j;

  if(low < high){
      j = partition(a, low, high);
      quickSort(a, low, j);
      quickSort(a, j+1, high);
    }
}

void merge(int *a, int low, int mid, int high){
  int i = low;
  int j = mid+1;
  int k = low;
  int b[100]; //check size

  while (i<=mid && j<=high) {
      if(a[i]<a[j])
        b[k++] = a[i++];
      else
        b[k++] = a[j++];
    }

  for(;i<=mid;i++)
    b[k++] = a[i];

  for(;j<=high;j++)
    b[k++] = a[j];

  for(int i=low; i<=high;i++)
    a[i] = b[i];
}

void mergeSort(int *a, int n){
  int p, low, high, mid, i;

  for (p = 2;p<=n;p=p*2) {
      for (i=0;i+p-1<n;i=i+p) {
          low = i;
          high = i + p -1;
          mid = (low+high)/2;
          merge(a, low, mid, high);
        }
    }

  if(p/2<n)
    merge(a, 0, p/2 - 1, n);
}

void recursiveMergeSort(int *a, int low, int high){
  int mid;

  if(low < high){
      mid = (low + high)/2;
      recursiveMergeSort(a, low, mid);
      recursiveMergeSort(a, mid + 1, high);
      merge(a, low, mid, high);
    }
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  int bubbleArr[] = {3, 7, 9, 10, 6, 5, 12, 4, 2, 11};
  int insertArr[] = {3, 7, 9, 10, 6, 5, 12, 4, 2, 11};
  int selectionArr[] = {3, 7, 9, 10, 6, 5, 12, 4, 2, 11};
  int quickSortArr[] = {3, 7, 9, 10, 6, 5, 12, 4, 2, 11, INT32_MAX};
  int mergeSortArr[] = {3, 7, 9, 10, 6, 5, 12, 4, 2, 11};
  int recMergeSortArr[] = {3, 7, 9, 10, 6, 5, 12, 4, 2, 11};
  int n = 10;

  cout << "Original Array: " ;
  display(bubbleArr, n);
  cout << "--------------------------------------" << endl;

  cout << "Bubble sort:    " ;
  bubbleSort(bubbleArr, n);
  display(bubbleArr, n);

  cout << "Insert sort:    " ;
  insertionSort(insertArr, n);
  display(insertArr, n);

  cout << "Selection sort: " ;
  selectionSort(selectionArr, n);
  display(selectionArr, n);

  cout << "Quick Sort:     " ;
  quickSort(quickSortArr, 0, n);
  display(quickSortArr, n);

  cout << "Merge Sort:     " ;
  mergeSort(mergeSortArr, n);
  display(mergeSortArr, n);

  cout << "Rec Merge Sort: " ;
  recursiveMergeSort(recMergeSortArr, 0, n);
  display(recMergeSortArr, n);

  return a.exec();
}
