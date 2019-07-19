#include <iostream>

using namespace std;

/*
 *  e^x = 1 + x/1 + (x^2)/2! + (x^3)/3! + ... + (x^n)/n!
*/
double exponential(int x, int n){
  static double power = 1, factorial = 1;
  double result;

  if(n == 0)
    return 1.0;
  else{
      result = exponential(x, n - 1);
      power = power * x;
      factorial = factorial * n;
      return result + power/factorial;
    }
}

int main()
{
  int number;
  double result;
  cout << "Exponential e^x" << endl;
  cout << "Enter x value: ";
  cin >> number;
  result = exponential(number, 10);
  cout << "result: " << result << endl;
  return 0;
}
