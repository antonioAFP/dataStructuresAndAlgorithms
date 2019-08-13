#include <iostream>

using namespace std;

class LowerTriangularMatrix{
private:
  int n;
  int *array;

public:
  LowerTriangularMatrix(){
    this->n = 2;
    array = new int[2*(2+1)/2];
  }

  LowerTriangularMatrix(int n){
    this->n = n;
    array = new int[n*(n+1)/2];
  }

  void set(int i, int j, int x);
  int get(int i, int j);
  void display();
  ~LowerTriangularMatrix();
};

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

LowerTriangularMatrix::~LowerTriangularMatrix(){
  delete []array;
}

int main()
{
  cout << "Hello World!" << endl;
  return 0;
}
