#include <iostream>

using namespace  std;


class CDummy{
private :
 static int n;
public :
 CDummy() { ++n; }
 ~CDummy() { --n; }
 static int getN() {return n;}  //static methods can only access static variables
};

int CDummy::n = 0;  //can only be defined once in this project, see cdummy.cpp

int main_2(){
	CDummy a;
    CDummy b[3];
	cout << CDummy::getN();  //note here, can only do these because only static methods can be called independent of the class instance
    cout << a.getN();
    cout << b[2].getN();
	return 0;
}
