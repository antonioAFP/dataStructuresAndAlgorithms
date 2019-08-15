#ifndef LOWERTRIANGULARMATRIX_H
#define LOWERTRIANGULARMATRIX_H

#include "Matrix.h"

/*
 * Representation:
 *
 * 1 0 0 0 0
 * 1 2 0 0 0
 * 1 2 3 0 0
 * 1 2 3 4 0
 * 1 2 3 4 5
*/

class LowerTriangularMatrix : Matrix
{
public:
  LowerTriangularMatrix();
  LowerTriangularMatrix(int n);

  void create();
  void set(int i, int j, int x);
  int get(int i, int j);
  void display();
  ~LowerTriangularMatrix();
};

#endif // LOWERTRIANGULARMATRIX_H
