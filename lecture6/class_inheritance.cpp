#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>

using namespace::std;

//some note here, I have no idea why need to put a reference & on the string class
//in dev c, it works with our wihtout that reference...


class Vehicle { 
 protected : 
 	string license; 
	int year;
 
 public :
  Vehicle( const string &myLicense, const int myYear) : license(myLicense), year(myYear) {}
  const string getDesc() const {return license + " from " ;}  
  const string &getLicense() const {return license;}  
  const int getYear() const {return year;} 
};

class Car : public Vehicle { //Makes Car inherit from Vehicle, what the hell is public?
	string style;

public:
	Car(const string &myLicense, const int myYear, const string &myStyle)  //note in the default constructor, the base class constructor is called
		:Vehicle(myLicense, myYear), style(myStyle) {}
	
	const string &getStyle() {return style;}
	const int getYear2() const {return year+5;}
};

//now, Car has all the members and functions of vehicle, with the additon of style and getStyle()
//note the public term in the inheritance -> you can actually specify private, protected, or public inheritance

//refer to wikipedia on how the inheritance work
//if say in the parent or base class, a member is private, regardless of the type of inheritance, the member is private
//  this implies that the member may not be accessed by a derived class, only the base class
//  example, functions inherited from the base class may access the member, but not new functions declared in the derived class

//if say in the parent class, a member is protected, this means that it will allow access from both base and derived class
//so now, all new functions in the derived class may access the protected member

//using protected or private inheritance, will potentiallty try to convert all member functions to have this accessibility
//not usually a good idea, since the existing method members may not be called on main...

int main_inheritance(void){
	
	Vehicle adventure("znl552",2008);
	cout << adventure.getYear() << "\n" << adventure.getLicense() << "\n";
	
	Car mazda3("wek211",2012,"skyactive");
	cout << mazda3.getYear() << "\n" << mazda3.getLicense() << "\n" << mazda3.getStyle() ;
	cout << mazda3.getYear2() << endl;

	return 0;
}


