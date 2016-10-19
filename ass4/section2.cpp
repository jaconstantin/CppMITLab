#include <iostream>
#define min_mac(x,y) (x < y ? x:y)

//BIG NOTE here, do not use namespsace std, since it already contains a min function

//Problem 2 Multi-type Min

template <typename T>
T min(const T a, const T b){
	return a < b ? a:b;
}

int main_section2(){
	std::cout << min<int>(20,13) << std::endl;
	std::cout << min<float>(20.001,20.05) << std::endl;
	std::cout << min_mac(20,100) << std::endl;
	
	
	return 0;
}



