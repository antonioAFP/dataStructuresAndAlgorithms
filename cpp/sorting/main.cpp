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

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  int bubbleArr[] = {3, 7, 9, 10, 6, 5, 12, 4, 2, 11};
  int insertArr[] = {3, 7, 9, 10, 6, 5, 12, 4, 2, 11};
  int selectionArr[] = {3, 7, 9, 10, 6, 5, 12, 4, 2, 11};
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

  return a.exec();
}
