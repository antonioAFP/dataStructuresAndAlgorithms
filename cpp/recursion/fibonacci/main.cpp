#include <iostream>

using namespace std;

int fibonacci(int n){
  if(n <= 1)
    return n;

    return fibonacci(n - 2) + fibonacci(n - 1);
}

int main()
{
  int number;
  cout << "-- Fibonacci --" << endl;
  cout << "Enter a number: ";
  cin >> number;
  cout << "Fibonacci of " << number << " is: " << fibonacci(number) << endl;
  return 0;
}
