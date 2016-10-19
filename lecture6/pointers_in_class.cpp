#include <iostream>
#include <cstdlib>
#include <cstring>
#include <stdio.h>

using namespace::std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

//refer to the class MIT student in main.cpp

class MITStudent {
	public:
		int *studentID;
		char *name;
		MITStudent() {
			studentID = 0;
			name = "jay";
					}
		//MITStudent(MITStudent &o) {
		//	studentID = o.studentID;
		//	name = strdup(o.name);
		//	}
		};
		
	
int main() {
	
	MITStudent student1,student2;
	//student1.name = "jay";
	//student2.name = "top";
	
	int ax = 95;
	
	//shows how to handle pointers in a struct
	//studentID is the pointer, but the pointer operator must be at the very start
	
	student1.studentID = &ax;
	student2.studentID = new int[1];
	*student2.studentID = 95; 

	
	cout <<student1.studentID << endl; //prints the address
	cout <<*student1.studentID << endl; //dereference the pointer
	
	cout <<student2.studentID << endl; //prints the address
	cout <<*student2.studentID << endl; //dereference the pointer
	
	MITStudent student3 = student1;
	
	cout <<student3.studentID << endl; //prints the address, shows it is the same as student1
	cout <<*student3.studentID << endl; //prints the value, shows it is the same as studnet1, so any change on 1 will affect the other
	
	cout << &(*student1.name) << endl;
	cout << &(*student3.name) << endl;
	
	char *str = "otep";
	
	printf("%s\n",(void*)str);  //it seems that printing a string as %p maybe for pointers, will indeed print the address but to confirm
	
	str = "joseph";
	
	cout << str << endl;
	char str2[] = "bernard";
	
	str = &str2[0];        //assigning an address to string should work, as well as assigning anohter string
	 					   //same function as str = str2;
	cout << str << endl;
	
	
	
	return 0;
}
