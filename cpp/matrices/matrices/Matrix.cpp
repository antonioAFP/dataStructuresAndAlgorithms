#include "Matrix.h"
#include <iostream>

using namespace std;

Matrix::Matrix(){
}

Matrix::~Matrix(){
  delete []array;
}
