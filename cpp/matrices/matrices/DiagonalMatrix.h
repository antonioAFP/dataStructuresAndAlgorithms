#ifndef DIAGONALMATRIX_H
#define DIAGONALMATRIX_H

#include "Matrix.h"

/*
 * Representation:
 *
 * 1 0 0 0 0
 * 0 2 0 0 0
 * 0 0 3 0 0
 * 0 0 0 4 0
 * 0 0 0 0 5
*/

class DiagonalMatrix : Matrix
{
public:
  DiagonalMatrix(int n);
  void create();
  void set(int i, int j, int x);
  int get(int i, int j);
  void display();
  ~DiagonalMatrix();
};

#endif // DIAGONALMATRIX_H
