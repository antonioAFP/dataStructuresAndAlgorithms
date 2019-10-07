#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

using namespace std;

class Matrix{
protected:
  int n;
  int *array;

public:
  Matrix();
  virtual void create() = 0;
  virtual void set(int i, int j, int x) = 0;
  virtual int get(int i, int j) = 0;
  virtual void display() = 0;
  ~Matrix();
};
#endif // MATRIX_H
