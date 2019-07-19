#include <iostream>

using namespace std;

int exponent(int m, int n){
  if(n == 0)
    return 1;
  else
    return exponent(m, n - 1) * m;
}

int main()
{
  int number;
  int exp;
  cout << "Exponent N of M, M^N" << endl;
  cout << "Enter number M: ";
  cin >> number;
  cout << "Enter exponent N: ";
  cin >> exp;
  cout << "M^N: " << exponent(number, exp) << endl;

  return 0;
}
