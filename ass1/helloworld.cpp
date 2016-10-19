#include <iostream>

using namespace std;

/*Problem 2.1
/*prints hello world
int main(void){
	
	const char *x = "Hello, World!";
	
	cout << x;
	return 0;
}
*/


//Problem 2.2
//print hello world n times
int hello(void){
	int n,x;
	cout << "enter n >>> ";
	cin >> n;
	
	x=1;
	do{
			cout << "Hello, World!\n";
			++x;
	}
	while(x<=n);
	
	 
}
