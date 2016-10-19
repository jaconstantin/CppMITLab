#include <iostream>
#include "geometry.h"


using namespace std;

//Problem 5.7
//main function for the polygon classs
//various testing routines

int main_old(){
	
 	PointArray p;
 	cout << p.getSize() << endl;
 	int x=0;
 	
 	Point a1,a2,a3,a4,a5;
 	a1.setX(1);
 	a1.setY(2);
 	a2.setX(3);
 	a2.setY(4);
 	a3.setX(5);
 	a3.setY(6);
 	a4.setX(7);
 	a4.setY(9);
 	
 	
 	p.push_back(a1);
 	p.push_back(a2);
 	p.push_back(a3);
 	p.push_back(a4);
    //x=1;
    //cout << p.getSize() << endl;
    
    p.resize(5);
    p.resize(10);
    p.resize(15);
    
    cout << p.getSize() << endl;
    cout << p.getSize() << endl;
   
    Point *read;
    
    read = p.get(1);
    cout << read->getX() << endl;
    cout << read->getY() << endl;
    
   // p.insert(1,a1);
    
    
    //cout << PA.p[0].getX() << PA.p[2].getY();

	return 0;
}


//this portion is to manually test the constructors of polygon
//assume her that member PA is public..

int Polygon::poly_n = 0;  //always declare static int like this first
/*
int main_polygon(){
	
	Point p1(1,1), p2(2,2), p3(3,3), p4(4,4);
	Point *p_array = new Point [5];
	Point *p_array_v2 = new Point[5];
	
	p_array[0].setX(1); p_array[0].setY(4);
	p_array[1].setX(2); p_array[1].setY(3);
	p_array[2].setX(3); p_array[2].setY(2);
	p_array[3].setX(4); p_array[3].setY(1);
	p_array[4].setX(5); p_array[4].setY(1);
	
	p_array_v2[0].setX(1); p_array[0].setY(4);
	p_array_v2[1].setX(2); p_array[1].setY(3);
	p_array_v2[2].setX(30); p_array[2].setY(2);
	p_array_v2[3].setX(4); p_array[3].setY(1);
	p_array_v2[4].setX(50); p_array[4].setY(10);
	
	/////////////////////////////
	//note, once we declare a virtual function in polygon can no longer instantiate one
	Polygon pol1(p_array,4);
	
	//cout << pol1.PA.get(3)->getX() << " " << pol1.PA.getSize() << endl;
	//cout << Polygon::poly_n << endl;
	
	
	/////////////////////
	PointArray p_array2(p_array,5);
	PointArray p_array2_v2(p_array_v2,5);
	
	PointArray p_array3 = p_array2_v2;
	
	//so far, experiments shows that assigning again p_array3 will no longer call the copy constructor
	//though, it is flagging an error...
	//p_array3 = p_array2_v2;
	
	
	Polygon pol2(p_array3);
	
	//cout << pol2.PA.get(4)->getX() << " " << pol2.PA.getSize() << endl;
	pol2.printPA();
	cout << "bye";
	cout << "beh";
	
	////////////////////////////invoke default copy contructor here
	///will work for point array member, since it has a custom cooy constructor
	//though the static n element will not get updated...
	//after writing custom copy constructor, now ok, see that in custom copy constructor, i simply equated PA to call its own copy constructor
	//also, with the default copy constructor, i encounter no error, but with the custom one, there is an error
	
	Polygon pol3 = pol1;
	pol3.printPA();
	
	//cout << pol3.PA.get(2)->getX() << " " << pol3.PA.getSize() << endl;
	
	//any time i reassign an object, i can confirm that copy constructor is not called, but assignment is called, since the value ass works
	//though, an error is always flagged
	//i think this has to do with the new operator here, no explicit delte, nor is there a destructor
	//but, the bad thing here, is if the copy constructor is not called, then how are sure that the fields are properly copied?
	
	
	//pol3 = pol2;
	//pol3.printPA();
	//cout << Polygon::poly_n << endl;
	cout << "bye bye new\n";
	
	cout << Polygon::getNumPolygons() << endl;
	cout << pol3.getNumSides() << endl;
		
	return 0;
	
}
*/

int main(void){
	Point p1(1,2), p2(3,4);
	
	//interesting note here, can directly use a point constructor as point arguments in functions
	Point *pa = updateConstructorPoints(p1,p2,Point(5,6),Point(0,0));
	
	cout << pa[0].getX() << " " << pa[1].getX() << " " << pa[2].getX() << " " << pa[3].getX() << endl;

	//Rectangle rec1(Point(1,2),Point(3,4));
	Rectangle rec1(p1,p2);
	Rectangle rec2(10,20,30,40);
	
	rec1.printPA(); //check the x value of PA[1] of rec1
	rec2.printPA();
	

	cout << rec1.area() << " " << rec2.area();	
	return 0;
}


int main_old34(){
	cout << "enter coords of triangle" << endl;
	
	int x1, y1, x2, y2, x3, y3;
	cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
	
	Point a(x1,y1), b(x2,y2), c(x3,y3);
	Triangle t(a,b,c);
	
	cout << t.area() << endl;
	cout << t.getPoints()->get(2)->getX();
	
	
	return 0;
}
