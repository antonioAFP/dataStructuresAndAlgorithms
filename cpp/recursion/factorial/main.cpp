/*
  Returns factorial of N
*/
#include <iostream>

using namespace std;

int factorial(int n){
  if(n == 0)
    return 1;
  return factorial(n - 1) * n;
}

int main()
{
  int number;
  cout << "Factorial of N" << endl;
  cout << "Enter a number: ";
  cin >> number;
  if(number > 0)
    cout << "Factorial: " << factorial(number) << endl;
  else
    cout << "Error, factorial is not defined for numbers less than zero";
  return 0;
}
