#include <iostream>

using namespace std;

//For Problem 2: Catch that bug

class Point {
  private :
    int x, y;

  public :
     Point (int u, int v) : x(u), y(v) {}
     int getX() const { return x; }
     int getY() const { return y; }
     void doubleVal ()
    {
      x *= 2;
      y *= 2;
    }
};

int main () {
   const Point myPoint (5, 3);
   //myPoint.doubleVal ();
   cout << myPoint . getX () << " " << myPoint . getY () << "\n";
   return 0;
}
