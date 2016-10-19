#include <iostream >

using namespace std;


//Problem 3.3 Prime Numbers
//Given 'N', print the prime numbers from 0 to N
int main_prime(void){
	
	int N;
	cin >> N;
	
	bool is_prime = true;
	
	for(int j=2; N>0; ++j){
		
		for(int i=2; i<j; ++i){
			if(j % i == 0) {
				is_prime = false;
				break;
				}
			is_prime = true;	
		} 
		
		if(is_prime==true) {
			--N;
			cout << j << "\n";
		}
		
	}
	
	
	
	return 0;
	
}

//Problem 3.4 Multiples of Numbers
//Write a program that loops indefinitely. 
//In each iteration of the loop, read in an integer N (declared as an int) that is inputted by a user, 
//output N5 if N is nonnegative and divisible by 5, and -1 otherwise.
//break the loop by inputting a negative number
int main_control(){
	
	int N;
	
	for(int x=0;x>=0;){
		cin >> N;
		
		if(N < 0) break;
		
		N = ((N > 0) && (N%5==0)) ? N/5 : -1; 
		cout << N << "\n";
		
		
	}
	
	cout << "good bye!";
	return 0;
}

  
#define O 1 // That ’s an oh, not a zero
int main_multiple(){

  {
  return O;
  }
}



