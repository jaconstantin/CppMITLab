#include <iostream>
#include "geometry.h"

//include geometry.h for this casting exercise
//remeber to define an int poly_n, which is the static int...

//Problem 3 Casting

using namespace std;

int Polygon::poly_n;

int main(){
	
	Rectangle rec2(10,20,30,40);
	int x=10;
	float y=0.02;
	
	cout << static_cast<float>(x) + y;
	
	Rectangle *shape = &rec2; 
	
	//static_cast<Triangle*>(shape); //does not compile, since this is not a valid type casting, not equivalent
	dynamic_cast<Triangle*>(shape); //note, dyanmic cast arguments must be both pointers...
	
	
	
	
	return 0;
}
