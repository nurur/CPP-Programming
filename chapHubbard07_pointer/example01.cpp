// Example 
// address operator, pointer, deference operator 


#include <iostream>
using namespace std;


int main ()
{
  int a;
  cout << "type an integer: "; 
  cin >> a;
  cout << endl;

  cout << "  a  = " << a  << endl;
  cout << "  &a = " << &a << endl;
  cout << endl;

  // address to a
  int& ra =  a;
  cout << "  ra = " << ra  << endl;
  cout << endl;

  // pointer to a 
  int* pa = &a;
  cout << "  pa = " << pa  << endl;
  cout << " &pa = " << &pa << endl;
  cout << " *pa = " << *pa << endl;  
  cout << endl;



  // pointer to a pointer
  int** ppa = &pa;
  cout << " ppa = " << ppa  << endl;
  cout << "&ppa = " << &ppa << endl;
  cout << "*ppa = " << *ppa << endl;


  // auxiliary 
  int x= 44;
  int y= 44;
  cout << x << " " << y << " " << &x << " " << &y << endl;

  int* xx = &x;
  int* yy = &y;
  cout << x << " " << y << " " << *xx << " " << *yy << endl;


  char c[]  = "hello";
  char s[6] = "hello";
  cout << c << " " << s << endl;


  return 0;
}
