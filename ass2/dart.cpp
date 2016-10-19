#include <iostream>

using namespace std;

#include <cstdlib > // C standard library 3 // defines rand(), srand(), RAND_MAX
#include <ctime> // C time functions -defines time()
#include <cmath>


//Problem 5, calculating PI
//using randomization modelled by a dart throw, compute for the value of PI

int main_dart(void){
	
	double n = 100000;
	
	double hit = 0;
	
	for(int i=0;i<n;++i){
		double x = rand()/(double)RAND_MAX, y = rand()/(double)RAND_MAX;
		double d = sqrt(x*x+y*y);
		//cout << x << "\t" << y << "\t" << d << "\n";
		
		if(d < 1) hit += 1;
	}
	
	
	
	double a = 4*hit/n;
	double pi = a;
	
	cout << "hit ->" << hit <<"\n pi ->" << pi;
	
	
	
	return 0;
}

//Problem 6.3 Array Operations
//Transpose a matrix

#define LENGTH  4
#define WIDTH 3

void transpose( const int input[][LENGTH], int output[][WIDTH]){
	for(int x=0; x<WIDTH; ++x){
		for(int y=0; y<LENGTH; ++y){
			output[y][x] = input[x][y];
		}
	} 
}


int main_array(){
	int input[3][4] = { {1,2,3,4}, {5,6,7,8}, {9,10,11,12} };
	int output[4][3] = {};
	
	
	cout << input[0][0] << input[1][2] << input[2][3]; 
	
	
	transpose(input,output);
	
	cout << output[0][0] << output[1][2] << output[2][3]; 
	
	return 0;
}


