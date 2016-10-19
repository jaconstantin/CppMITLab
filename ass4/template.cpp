#include <iostream>


using namespace std;

//identifier T will be replace by what you put in <>
//can be used in any way that makes sense after substitution

//Notes and explorations on templates...

template <typename T>
T sum(const T a, const T b) {
	return a + b;
}

template <typename T, typename U>
U sum(const T a, const U b){
	return a + b;
}

template <typename T>
class Point {
	private:
		T x, y;
	public:
		Point(const T u, const T v): x(u), y(v) {}
		T getX() {return x;}
		T getY() {return y;}
		T getXY();
};



//declaring class member functions outside the class
template <typename T>
T Point<T>::getXY() {return x+y;}

//declaring template specialtizations
//specialize the class for a specific float
template <>
class Point<float> {
	private:
		float x,y;
	public:
		Point(const float u, const float v): x(u), y(v) {}
		float getX() {return x+0.001;}
		float getY() {return y+0.001;}
		float getXY() {return x+y+0.002;
		}
};

int main_old(void){
	
	cout << sum<int>(1,2) << endl;
	cout << sum<float>(1.21, 2.43) << endl;
	
	//possible to invoke without a type, if the function parameter is the same as the return type
	cout << sum(1,2) << endl;
	cout << sum(1.21, 2.43) << endl;
	
	//demonstrates template with more than 1 parameter
	//also demonstrates function overloading
	cout << sum<int, float>(1, 2.5) << endl;
	cout << sum(2, 3.5) << endl;
	
	
	Point<float> fpoint(2.5, 3.6);
	Point<int> ipoint(2,10);
	
	cout << fpoint.getX() << " " << fpoint.getY() << " " << fpoint.getXY() << endl;
	cout << ipoint.getX() << " " << ipoint.getY() << " " << ipoint.getXY() << endl;
	
	return 0;
}
