#include <iostream>

using namespace  std;

//Demo programs for static members

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

class CDummy{
 public :
  static int n;
  CDummy() { ++n; }
  ~CDummy() { --n; }
};

//int CDummy::n = 0;      //wth is this notation? -> declares the variable n, which is of class CDummy
					    //static int is like a global variable, won't compile without this declaration

int main_1(){
CDummy a;
CDummy b[5];
CDummy* c = new CDummy;
cout << a.n << "\n"; // prints out 7
delete c;
cout << CDummy::n << "\n"; // prints out 6
return 0;
}
