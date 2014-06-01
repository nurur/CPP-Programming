// Example 
// Offsets of Structure Elements


#include <cstdlib>
#include <iostream>
using namespace std;


struct a
{
  struct b
  {
    int i; float f1; char c1;
  }x;

  struct c
  {
    int j; float f2; char c2;
  }y;

}z;


/*void fun(stuct c* p)
{
  int offset;
  strcut b *address;
}
*/


int main()
{
  //z.x.i =  10;
  //z.x.f1= 2.5;
  //z.x.c1= 'a';
  
  cout << z.x.i << ", " << z.x.f1 << ", " << z.x.c1 << endl;

  return 0;
}
