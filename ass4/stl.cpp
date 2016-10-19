#include <iostream>
#include <set>

//notes on STL

//STL, standard template library contains lots of useful container classes and algos
//containers, are data structures that can store objects, such as arrays...
//hence container classes are classes that can store multiple objects

//example here, let us use set - a class container 
//here, all elements are automatically sorted using binary search
//see that its advantage over arrays etc, is its special auto sort functionality, that is done upon insertion?
//also, upon a new element, it seems that an allocator is also called

using namespace std;

//note here, 'typename' and 'class' keywords are interchangeable for templates

template <class T>
T sum_c(const T a, const T b) {
	return a + b;

}


int main_stl(){
	
	cout << sum_c(10,20);
	
	set <int> iset;
	iset.insert(5);
	iset.insert(9);
	iset.insert(1);
	iset.insert(8);
	iset.insert(3);
	
	//again, use of iterator to access the contents, as it can't be accessed with []
	
	cout << "iset contains:"; 
	set<int>::iterator it;
	for(it=iset.begin(); it != iset.end(); it++) cout << " " << *it;
	cout << endl;
	
	return 0;
	
	
}

//furhter notes: look for more STL, and also look on algorithms
//finally, remember that templates may also be parametrized
