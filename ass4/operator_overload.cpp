#include <iostream>

using namespace std;

//various notes and practice on operator overloading

//note here it seems that a struct in c++ is also like a class, which can have its member functions, no typedef needed
//though in a struct, by default, an element is public in contrast to a 

//example here, include a function in USCurrency that will overload the operator + -> see the return value type and input arguments
//note the context, wherein the + function is being done according to the perspective of the element at the left of "+", that is why there is only one more addend in the input arguments, the one in the right side of "+"
//note that operation overlaod can also be done outside of the class definition... but then, will need to have two addend in the syntax
//USCurrency operator+(const USCurrency m, const USCurrency n){} -> as long as the input arguments is USCurrency, then the compiler will be able to relay that as the + operator for USCurrency
//also note of the syntax for overloading the  << stream operators... data type is "ostream"
// cout << a -------> cout =>> ostream &output, a ==>> USCurrency o
//as of now, can't get the syntax right for overloading << inside the class definition, maybe not possible since the class is on the left of << ?

struct USCurrency{
	int dollars;
	int cents;
	
	USCurrency operator+(const USCurrency o);
	//ostream& operator<<(ostream &output);
	
};

USCurrency USCurrency::operator+(const USCurrency o){
	USCurrency tmp = {0,0};
	tmp.cents = cents + o.cents;
	tmp.dollars = dollars + o.dollars;
	
	return tmp;
}

ostream& operator<<(ostream &output, const USCurrency &o){
	output << "$" << o.dollars << "." << o.cents;
	return output;
}

int main_overload1(){
	USCurrency a = {2, 50};
	USCurrency b = {1, 75};
	USCurrency c = a + b;	
	
	cout << a;
	
	return 0;
}



///friend functions - when you want to give a function, full access rights to private members of a class, usual for operator overload
//example, the << overload is not a member of the function, if ever the USdollars class has private members, then
//just type in the syntax shown preceded by keyword "friend"
//then, the overloaded << operator now has full access to the private members
//note that classes can also be friends to another class

class USdollars{
	friend ostream& operator<<(ostream &o, const USdollars &c);
	int dollar, cents;
public:
	USdollars(const int d, const int c): dollar(d), cents(c){}
};


ostream& operator<<(ostream &o, const USdollars &c){
	cout << "$" << c.dollar << "." << c.cents;
}


//writing a friend function for  a templated class :: HEADACHE!!! requires a very delicate syntax turn around!!
//first note, the friend function must also be templated so that it can become a friend function of a templated class.
//as comapared to non template classes and friend functions, this time, the templated function prototype must come before the class definition

//so, have a templated class declaration first
template <typename T>
class USmoney;

//then, have a templated full function prototype or definition
//note here, we are templating operator+, so operator+ do not use <>, on the other hand, the class is using <>
//here, we are already defining that the templated operator works on USmoney<>
//also shows that in function templates, it can work like this, together with templated class...
template <typename T>
USmoney<T> operator+(USmoney<T> &p, USmoney<T> &o){
	USmoney<T> tmp(0,0);
	tmp.cents = p.cents + o.cents;
	tmp.dollar = p.dollar  + o.dollar;
	return tmp;
}

//then declared the templated class
//here, in the friend statement, ensure that operator has the symbol <> to denote that it is templated, but not <T>
//instead, seems that it will just inherent the <T> type of class, as it was defined on its function
//also, since we are templating USmoney, it won't use of any <>....
template <typename T>
class USmoney{
	friend USmoney operator+<>(USmoney &p, USmoney &o);
	T dollar, cents;
public:
	USmoney(const T d, const T c): dollar(d), cents(c){}
	void USmoney_print(){
		cout << dollar << " " << cents << endl;}
};




int main(){
	USdollars a(3,75), b(4,68);
	cout << a << endl << b << endl;
	
	USmoney<float> c(3.01,4.05), d(6.5,3.3);
	USmoney<float> e = c+d;
	e.USmoney_print();
	
	USmoney<int> f(3,4), g(6,3);
	USmoney<int> h = f+g;
	h.USmoney_print();
	
	
	return 0;
}
