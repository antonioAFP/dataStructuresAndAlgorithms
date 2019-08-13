#include <iostream>

using namespace std;

class DiagonalMatrix{
private:
  int n;
  int *array;

public:
  DiagonalMatrix(int n){
    this->n = n;
    array = new int[n];
  }

  void set(int i, int j, int x);
  int get(int i, int j);
  void display();
  ~DiagonalMatrix();
};

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

DiagonalMatrix::~DiagonalMatrix(){
  delete []array;
}

int main()
{
  cout << "Hello World!" << endl;
  return 0;
}
