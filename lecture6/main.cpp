#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace::std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


class MITStudent {
	public:
		int *studentID;
		char *name;
		MITStudent() {
			studentID = 0;
			name = "";
					}
		//MITStudent(MITStudent &o) {
		//	studentID = o.studentID;
		//	name = strdup(o.name);
		//	}
		};


//studying here the default copy constructors
//whenver an entire instance is equated to another instance, all fields will be copied
//the unique thing here is that, say equated studen1 = student2, changing a single character of student1 name also change student2 and vice versa
//though, if an entire field is modified, say the ENTIRE name, or the student number, changing one does not affec the other
//why is this? -> a thing for research

//but with the additional custom copy constructor, this phenomenon is now gone
//it seems that this problem is only for string, or characters, as you can see, the new copy constructor, instead of directly assigning to o.name, a string duplicate function was used
//i think the danger for the copy constructors is for pointers, 
//default copy constructors will only copy all fields, so if pointers, there is a chance that it will point to the same address as the original one
//however, if we modify the entire string, maybe another address is now used... though, i can't access the address of the first element of string
int main_class() {
/*	
	MITStudent student1;
	student1.studentID = 98;
	char n[] = "foo";
	student1.name = n;
	MITStudent student2 = student1;
	
	cout << student2.name << endl; // foo
		
	student2.name[2] = 'e';
	
	cout << student1.name << endl; // foe
	
	student1.name[2] = 'm';
	cout << student2.name << endl; // fom
	cout << student1.name << endl; // fom
	
	cout <<student1.studentID << endl; //98
	cout <<student2.studentID << endl; //98
	
	student2.studentID = 64;
	cout <<student1.studentID << endl; //98
	cout <<student2.studentID << endl; //64
	
*/	
	
	int x[4] = {1,2,3,4};
	int y[4];
	
	y[0] = x[0];
	y[1] = x[1];
	y[2] = x[2];
	y[3] = x[3];
	
	
	y[3] = 10;
	
	cout << x[0] <<" " << x[1] << " " << x[2] << " " << x[3] << "\n";
	cout << y[0] <<" " << y[1] << " " << y[2] << " " << y[3] << "\n";
	
	return 0;
}
