#include <iostream>

using namespace std;

/*
 * n: Disk's number
 * a: Column Source
 * b: Column 'using' or auxiliar
 * c: Column Destination
*/
void hanoi(int n, int a, int b, int c){
  if(n > 0){
      hanoi(n - 1, a, c, b);
      printf("(%d, %d)\n", a, c);
      hanoi(n - 1, b, a, c);
    }
}

int main()
{
  int number;
  cout << "- Hanoi's Towers -" << endl;
  cout << "Enter diks number: ";
  cin >> number;
  cout << "Steps:" << endl;
  hanoi(3, 1, 2, 3);
  return 0;
}
