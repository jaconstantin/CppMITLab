#include <iostream >

using namespace std;

double get_ave(int*, int);
void get_mmr(int*, int, int*, int*, int&);


//Problem 3.2 Basic Statistics
//get min, max, mean, and range
int main_stat1(void){
	int N, *n_array, x;
	int min, max, range;
	cout << "enter N ->";
	cin >> N;
	
	n_array = new int[N-1];
	cout << "provide the numbers:";
	
	for(x=0;x<N;++x){
		cin >> n_array[x];
	}
	
	cout << "Mean: " << get_ave(n_array,N) << "\n";
	
	get_mmr(n_array, N, &min, &max, range);
	
	cout << "Min: " << min << "\n";
	cout << "Max: " << max << "\n";
	cout << "Range: " << range << "\n";


	delete [] n_array;
	return 0;
}

double get_ave(int in_array[], int length){
	int x;
	double ave = 0;
	for(x=0;x<length;++x)	ave = ave + in_array[x];
	return ave/length;
}

void get_mmr(int in_array[], int length, int *min, int *max, int &range){
	int x; 
	*min = in_array[0];
	*max = in_array[0];
	range = in_array[0];
	
	
	for(x=1; x<length;++x){
		if(*min > in_array[x]) *min = in_array[x];
		if(*max < in_array[x]) *max = in_array[x];
	}
	range = *max-*min;
	return;
}
