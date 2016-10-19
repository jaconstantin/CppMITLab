#include <iostream >

using namespace std;


//sample code for Problem 3.1 Scope
int main_scope()
 {
 int arg1;
 arg1 = -1;
   {
   char arg1 = 'A';
   cout << arg1 << "\n";
   }
 return 0;
}
