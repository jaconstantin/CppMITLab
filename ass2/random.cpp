#include <iostream>

using namespace std;

#include <iostream >
#include <cstdlib > // C standard library 3 // defines rand(), srand(), RAND_MAX
#include <ctime> // C time functions -defines time()

int main_random() {
  srand( time(0) ); // Set the seed;
  // time(0) returns current time as a number
  int randNum = rand();
  cout << "A random number: " << randNum << endl;
  return 0;
}


//Problem 4.6
//a sum function for  N integers using recursion
//take note of how recursion is usually done...

int getSum(const int numbers[], const int num_len){
	
	if(num_len == 0){
		return 0;
	}
	else{
		return numbers[num_len-1]+getSum(numbers,num_len-1);
	}
	
}

//Problem 4.5
//a sum function for N integers using a loop

//using array in functions
//you can declare array as function arguments without any dimensions, handle it like a string
//so, when you call the function, the argument that you put on the array, should be the address, eg, see the codes here

void printNum(int);

int main_sum() {
 printNum(35);
 int numbers[] = {1,2,3,4,5,6,7,8,9};
 
 
 cout << "\n" << getSum(numbers,8);
 
 return 0;
}

void printNum(int number) { 
  cout << number;
}
