//#include <iostream>

//using namespace std;


class Point{
	private:
		int x, y;
	public:
		Point(int a=0, int b=0):x(a),y(b) {};
		int getX() const{ return x;}
		int getY() const{ return y;}
		void setX(const int new_x) {x = new_x;}
		void setY(const int new_y) {y = new_y;}
		
};

class PointArray{
	private:
		Point *p;
		int p_size;
		
		//void resize(int n);
	public:
	
		PointArray();
		PointArray(const Point points[], const int size);
		PointArray(const PointArray &pv);
		~PointArray(){ delete [] p; }
		
		void resize(int n);
		
		void push_back(const Point &pt); 
		void insert(const int position, const Point &pt);
		void remove(const int pos);
		int getSize() const {return p_size;}
		void clear();
		Point *get(const int position) {return (p+position); }
		const Point *get(const int position) const {return (p+position); } //need this const version for the area function, ->a const function, so it needs to return a const pointer as well
};

//note the use of reference in &arg_PA
//why use it instead of just arg_PA - for efficieny
//so that we do not need to copy in the entire arg_PA array everytime the function is called, instead just reference it


//note, in member initializer syntax, to initiailze the point array of a polygon, one can invoke the constructor of its' point array

class Polygon{
	protected:
	    static int poly_n;
		PointArray PA;
	public:
		
		
		Polygon(const Point points[], const int size):PA(points,size){ ++poly_n; }
		Polygon(PointArray &arg_PA);
		Polygon(const Polygon &tocpy_poly);
	
		virtual double area() const = 0;
		static int getNumPolygons() {return poly_n;}
		int getNumSides() const {return PA.getSize();}
		const PointArray *getPoints() const {return &PA; }
		~Polygon() {--poly_n;}
		
		void printPA();
};


class Rectangle : public Polygon { //rectangle as subclass of polygon
	public: 
		Rectangle(const Point &p1, const Point &p2);
		Rectangle(const int n1, const int n2, const int n3, const int n4);
		
		virtual double area() const; //note, declaration here is still virtual
};

Point *updateConstructorPoints( const Point &p1, const Point &p2, const Point &p3, const Point &p4);

class Triangle : public Polygon {
	public:
		Triangle(const Point &p1, const Point &p2, const Point &p3);
		virtual double area() const;
};



