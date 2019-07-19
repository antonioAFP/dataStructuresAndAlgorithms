#include <iostream>

using namespace std;

int sumNaturalNumbers(int n){
  if(n == 0)
    return 0;
  return sumNaturalNumbers(n - 1) + n;
}

int main()
{
  int number;
  cout << "Sum Natural Numbers" << endl;
  cout << "Enter a number: " << endl;
  cin >> number;
  cout << "Sum: " << sumNaturalNumbers(number) << endl;
  return 0;
}
