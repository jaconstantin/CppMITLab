#include <iostream>

using namespace std;

//Problem 7, Pointers and String

int string_len(char *);


//Problem 7.2
//swap two integer values via pointers and reference
void swap_int_ptr(int *x, int *y){
	int z = *x;
	*x = *y;
	*y = z;
}


//note for pointers, when declaring pointer *p, it is equated to the equivalent address
//after decalration, *p dereference the content of thea address in p, while p will give the address
//the same goes for return values

//for references &x, when declaring a reference, it is equated to a variable containing a value
//after declaration, &x contains the address of the variable, x contains the value of the variable

void swap_int_ref(int &x, int &y){
	int z = x;
	x = y;
	y = z;
}


int main_part1(void){
	
	char *word = "helloo";
	int x = 4, y = 7, a = 3, b = 4;
	
	cout << "the length is =>" << string_len("otep the great") << "\n";
	
	cout << x << "\t" << y << "\n";

	swap_int_ref(x,y);
	cout << x << "\t" << y << "\n";
	
	swap_int_ptr(&x,&y);
	cout << x << "\t" << y << "\n";
	
	return 0;
}

//Problem 7.4
//this function performs a swap differently
//instead of swapping values, it swaps two pointers to point to each other
void swap(int **x, int **y) {   //declare pointer to pointers
int *tmp = *x;                  //then, a single * means that we are dereferencing the address of the pointers
*x = *y;                        //in effect, we are swapping addresses
*y = tmp;                       //notice, *tmp=*x, means tmp will contain the address *x
}

int main_part2(void){
	int x=5, y=6;
	int *ptr1 = &x, *ptr2 = &y;

	swap(&ptr1, &ptr2);
	cout << *ptr1 << ' ' << *ptr2;
}

//Problem 7.5
//follow the pointer operations in the PDF
int main(void){
	char *oddOrEven = "Never odd or even";
	
	char *nthCharPtr = (oddOrEven+5);  
	nthCharPtr -= 2;
	cout << *nthCharPtr << "\n";
	
	char **pointerPtr = &nthCharPtr;
	cout << pointerPtr << "\n";
	cout << **pointerPtr << "\n";
	
	nthCharPtr += 1;
	
	cout << nthCharPtr - oddOrEven << "\n";
	return 0;
}


int string_len(char *str){
	
	int x=0;
	while(str[x] != NULL){
		++x;
	}
		
	return x;
}
