#include <iostream>
//#include <conio.h>

using namespace std;

void fun(int n){
 if(n > 0){
      cout << n;
      fun(n - 1);
      fun(n - 1);
 }
}


int main()
{
  fun(4);
  cout << "Hello World!" << endl;
  //cin.get();
  return 0;
}

/*
 * #include <cstdlib>
#include <iostream>

using namespace std;

void fun(int n){
 if(n > 0){
      //cout() << "n";
      fun(n - 1);
      fun(n - 1);
 }
}

int main(int argc, char *argv[])
{
    fun(5);
    system("PAUSE");
    return EXIT_SUCCESS;
}

*/
