#include <iostream >

using namespace std;

//create a code to find a factorial
int main(){
 short number;
 cout << "Enter a number: ";
 cin >> number;
 
 if(number < 0){
 	cout << "factorial not defined for negative numbers";
 	return 0;
 }

 cout << "The factorial of " << number << " is ";
 long long accumulator = 1;
 for (; number > 0; accumulator *= number--);
 cout << accumulator << ".\n";

return 0;

}

