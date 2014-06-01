// Example: 10.14, 10.15, 10.16
// Static data field and Static member function 
// Note: 
// Static member functions can access ONLY Static data members 
// from their own Class 



#include <iostream>
using namespace std;


// static data field 
class Widget1
{
public:
  Widget1() { ++count; }
 ~Widget1() { --count; }
  static int count;
};

int Widget1 :: count = 0;


// static data field 
class Widget2
{
public:
  Widget2() { ++count; }
 ~Widget2() { --count; }

  int numWidget() { return count; }          // access function 

private:
  static int count;
};

int Widget2 :: count = 0;



// static data field & static member function 
class Widget3
{
public:
  Widget3() { ++count; }
 ~Widget3() { --count; }

  static int numWidget() { return count; }   // static access function 

private:
  static int count;
};

int Widget3 :: count = 0;





int main()
{
  // part 1
  Widget1 x1, y1;
  cout << "Now there area "   << x1.count << " widgets" << endl;
  
  {
    Widget1 u1, v1, w1, z1;
    cout << "Now there area " << x1.count << " widgets" << endl;
  }
  cout << "Now there area " << x1.count << " widgets" << endl;
  
  Widget1 z1;
  cout << "Now there area "   << x1.count << " widgets" << endl;
  cout << endl;
  

 
  // part 2
  Widget2 x2, y2;
  cout << "Now there area "   << x2.numWidget() << " widgets" << endl;
  
  {
    Widget2 u2, v2, w2, z2;
    cout << "Now there area " << x2.numWidget() << " widgets" << endl;
  }
  cout << "Now there area " << x2.numWidget() << " widgets" << endl;
  
  Widget2 z2;
  cout << "Now there area "   << x2.numWidget() << " widgets" << endl;
  cout << endl;



  // part 3
  cout << "Now there area "   << Widget3::numWidget() << " widgets" << endl;

  Widget3 x3, y3;
  cout << "Now there area "   << Widget3::numWidget() << " widgets" << endl;
  
  {
    Widget3 u3, v3, w3, z3;
    cout << "Now there area " << Widget3::numWidget() << " widgets" << endl;
  }
  cout << "Now there area " << Widget3::numWidget() << " widgets" << endl;
  
  Widget3 z3;
  cout << "Now there area "   << Widget3::numWidget() << " widgets" << endl;
  

  cout << endl;
  return 0;
}

