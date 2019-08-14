#include "DiagonalMatrix.h"

DiagonalMatrix::DiagonalMatrix(int n) : Matrix(){
  this->n = n;
  array = new int[n];
}

void DiagonalMatrix::set(int i, int j, int x){
  if(i == j)
    array[i -1] = x;
}
int DiagonalMatrix::get(int i, int j){
  if(i == j)
    return array[i -1];
  else
    return 0;
}

void DiagonalMatrix::display(){
  for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
          if(i == j)
            cout << array[i - 1] << " ";
          else
            cout << "0 ";
        }
      cout << endl;
    }
}

