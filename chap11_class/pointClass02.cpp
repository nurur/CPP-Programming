/* Point Class
program with 'inline' functions
int get_x() and int get_y() are inlined
*/


#include <iostream>
using namespace std;


class Point {
private:             // data members
  int x, y;
  
public:              // function members 
  void set(int new_x, int new_y);

  int get_x() {return x;}   //inline
  int get_y() {return y;}   //inline 
};



int main() {
  Point pt1, pt2;

  pt1.set(10,20);
  cout << "pt1 is: " << pt1.get_x() << ", " << pt1.get_y() << endl;

  pt2.set(-15,-25);
  cout << "pt2 is: " << pt2.get_x() << ", " << pt2.get_y() << endl;

  return 0;
}




void Point::set(int new_x, int new_y){
  if (new_x < 0)
    new_x *= -1;
  
  if (new_y < 0)
    new_y *= -1;
  
  x=new_x;
  y=new_y;
}
