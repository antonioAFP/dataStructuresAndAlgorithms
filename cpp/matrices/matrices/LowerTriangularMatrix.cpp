#include "LowerTriangularMatrix.h"

LowerTriangularMatrix::LowerTriangularMatrix() : Matrix(){
  this->n = 2;
  array = new int[2*(2+1)/2];
}

LowerTriangularMatrix::LowerTriangularMatrix(int n) : Matrix(){
  this->n = n;
  array = new int[n*(n+1)/2];
}

void LowerTriangularMatrix::create(){
  int x;
  for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
          cin >> x;
          if(i >= j)
            array[i * (i - 1) / 2 + j - 1] = x;
        }
    }
}

void LowerTriangularMatrix::set(int i, int j, int x){
  if(i >= j)
    array[i*(i-1)/2 + j-1] = x;
}

int LowerTriangularMatrix::get(int i, int j){
  if(i >= j)
    return array[i*(i-1)/2 + j-1];
  else
    return 0;
}

void LowerTriangularMatrix::display(){
  for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
          if(i >= j)
            cout << array[i*(i-1)/2 + j-1] << " ";
          else
            cout << "0 ";
        }
      cout << endl;
    }
}
