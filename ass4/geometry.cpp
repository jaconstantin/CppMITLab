#include "geometry.h"
#include <iostream>
#include <math.h>
using namespace std;

PointArray::PointArray(){
	p = new Point[0];
	p_size = 0;
}

PointArray::PointArray(const Point points[], const int size){
	p = new Point[size];
	p_size = size;
	for(int i=0; i<size; ++i){p[i] = points[i];}
}


PointArray::PointArray(const PointArray &pv){
	cout << "copy constructor called\n";
	p_size = pv.p_size;
	p = new Point [pv.p_size];
	for(int i=0; i<p_size; ++i){p[i] = pv.p[i];}
}

void PointArray::resize(int n){
	Point *new_p = new Point [n];
	int minSize = (n > p_size ? p_size : n);
	for(int i=0; i<minSize; ++i) {new_p[i] = p[i];}
	p_size = n;
	delete[] p;
	p = new_p;
	
}

void PointArray::push_back(const Point &pt){
	resize(p_size+1);
	p[p_size-1] = pt;
}

void PointArray::insert(const int position, const Point &pt){
	resize(p_size+1);
	//for(int i=p_size-2;i>=position;--i){p[i+1] = p[i]; }
	//p[position] = pt;
}

void PointArray::remove(const int pos){
	for(int i=pos; i<p_size-2;++i){p[i] = p[i+1]; }
	resize(p_size-1);
}

void PointArray::clear(){
	resize(0);
}


//polygon functions
//one possible implementation, wherein the copy constructor of point array will be invoked
/*
Polygon::Polygon(PointArray &arg_PA){
	PA = arg_PA;
	++poly_n;
}*/

//or this, member init syntax, call pointarray constructor of PA
Polygon::Polygon(PointArray &arg_PA):PA(arg_PA) {
	++poly_n;
}


//using the member initializer syntax allows this to work
//allows to call a constructor
Polygon::Polygon(const Polygon &tocpy_poly):PA(tocpy_poly.PA){
	cout << "poly copy constructor called\n";
	//PA = tocpy_poly.PA;  //for some reason, this works but cause terrible error
	                       //also note, it seems that this won't call the copy constructor, because we did not declare PA, it is already declared, hence memory violation
	++poly_n;
}

void Polygon::printPA(){cout << PA.get(1)->getX() << endl;}


//Rectangle functions
Point constructorPoints[4];

Point *updateConstructorPoints( const Point &p1, const Point &p2, const Point &p3, const Point &p4 = Point(0,0)) {
constructorPoints[0] = p1;
constructorPoints[1] = p2;
constructorPoints[2] = p3;
constructorPoints[3] = p4;
return constructorPoints;
}

Rectangle::Rectangle(const Point &p1, const Point &p2):Polygon(updateConstructorPoints(p1,p2,Point(0,0)),2){}
Rectangle::Rectangle(const int n1, const int n2, const int n3, const int n4):Polygon(updateConstructorPoints(Point(n1,n2),Point(n3,n4),Point(0,0)),2){}
	
double Rectangle::area() const {
	double length =  abs( ((double)PA.get(0)->getX()) - ((double)PA.get(1)->getX()) );
	double width =  abs( ((double)PA.get(0)->getY()) - ((double)PA.get(1)->getY()) );
	return length*width;
	}


Triangle::Triangle(const Point &p1, const Point &p2, const Point &p3):Polygon(updateConstructorPoints(p1,p2,p3),3){}


double Triangle::area() const {
	int dx01 = PA.get(0) ->getX() -PA.get(1) ->getX(),
        dx12 = PA.get(1) ->getX() -PA.get(2) ->getX(),
        dx20 = PA.get(2) ->getX() -PA.get(0) ->getX();
    int dy01 = PA.get(0) ->getY() -PA.get(1) ->getY(),
        dy12 = PA.get(1) ->getY() -PA.get(2) ->getY(),
        dy20 = PA.get(2) ->getY() -PA.get(0) ->getY();

   double a = sqrt(dx01*dx01 + dy01*dy01),
          b = sqrt(dx12*dx12 + dy12*dy12),
          c = sqrt(dx20*dx20 + dy20*dy20);

   double s=(a +b+c) /2;

   return sqrt( s * (s-a) * (s-b) * (s-c) );	
}


