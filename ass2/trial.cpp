#include <iostream>
#include <cstdlib >

using namespace std;

//Not part of the assignment
//various explorations on how pointers work and random number generation

void printNTimes( char *msg, int n) {
  for ( int i=0; i<n; ++i) {
  cout << msg;
  }
}


void setString( char **strPtr) {
 int x;
 cin >> x;
 if(x < 0)
  *strPtr = "Negative!";
 else
  *strPtr = "Nonnegative!";
}


//for pointer to pointers, note that the pointer is **strPtr, whose address is *strPtr, so this can be used to assign or dereference the string value


int * getRandNumPtr(){
 //int x = rand ();
 
 int *x = new int [0];
 *x = rand();
  
 cout << *x << "\n";
 //return &x;
 
 return x;
}


int main_pointers(void){
	
	int *randNumPtr = getRandNumPtr();
    cout << *randNumPtr; // ERROR
	
	const char *suitNames[] = {"Clubs ", "Diamonds ", "Spades ", "Clubs "};
	cout << suitNames[0] << "\n"; //clubs
	cout << suitNames[1] << "\n"; //daimonds
	cout << *suitNames << "\n";   //clubs
	cout << suitNames << "\n";    //some address
	
	//array of pointers, eg array of strings, can be accessed as normal arrays, and not as pointer to pointers
	//or, in this case, *suitNames[] is the array, so suitNames[] is like the array of addresses, which will dereference the string
	
	cout << *suitNames[0] << "\n"; //c
	
	
	char *str;
	setString(&str);
	cout << str;
	
	char *msg;	
	msg = "hello";
	//*msg = "hello";
	cout << msg << "\n";
    cout << *msg << "\n";
	cout << msg[0] << "\n";	
	
//for strings, it is considered as an array of characters
//to dereference the entire string, we use the address
//   example, int_array[x] and char_array[x], int_array will provide the address of element 0, while char_array will provide the entire string
//   *char_array and *int_array will dereference element 0 of the array
	
	
	char *msg_array = new char [2];
	msg_array[0] = 'o';
	msg_array[1] = 't';
	msg_array[2] = 'e';	
	
	cout << msg_array[0] << "\n";
	cout << msg_array[1] << "\n";
	cout << msg_array[2] << "\n";
	cout << *msg_array << "\n";
	cout << msg_array << "\n";
	cout << &msg_array << "\n";
	
	int *n;
	n = new int [2];
	//n = (int*)malloc(3*sizeof(int));
	n[0] = 0;
	n[1] = 1;
	n[2] = 2;
	n[10] = 10;
	
	//do not flag an error even if n has only  been allocated for 2 elements, it can add up to .....
	//for normal arrays, say int array n[2]
	
	
	
	cout << n[0] << "\n";  //dereference element 0
	cout << n[1] << "\n";  //dereference element 1
	cout << n[2] << "\n";
	cout << n[10] << "\n";
	cout << *n << "\n";    //dereference the first element, which is 1
	cout << n << "\n";     //output the address of the first element
	cout << &n << "\n";    //output the address of the pointer to the first element
	
	cout << &n[0] << "\n";
	cout << &n[1] << "\n";
	cout << &n[2] << "\n";	
	cout << sizeof(int) << "]n";
	
	return 0;
}
