#include <QCoreApplication>

void swap(int &a, int &b){
  int tmp = a;
  b = a;
  a = tmp;
}

void bubbleSort(int *a, int n){
  for (int i = 0;i < n - 1; i++) {
      for(int j = 0; j < n - 1 - i; j++){
          if(a[j] > a[j + 1])
            swap(a[j], a[j + 1]);
        }

    }
}

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);

  return a.exec();
}
