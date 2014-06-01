
#include <cstdlib>
#include <iostream>
using namespace std;


class A 
{
public:
   int x;
  
  A(int xx=0) { x=xx; }
  A& operator=(A& a) 
  {
    x=a.x;
    return *this;
  }
};


int main()
{
  int a=1, b=2, c=3;
  a=b=c;
  cout << a << " " << b << " " << c << endl;
  
  int p=1, q=2, r=3;
  p=(q=r);
  cout << p << " " << q << " " << r << endl;
  
  int d=1, e=2, f=3;
  (d=e)=f;
  cout << d << " " << e << " " << f << endl;
  
  A g,h,i(6);
  (g=h) = i;  // explicit grouping overrides normal right-associativity!
  cout << g.x << " " << h.x << " " << i.x << endl;
 


  cout << "Hello World!" << endl;
  exit(1);
  cout << "This line is after exit() function "
       << "It will nevere be executed!" << endl;
  
  return 0;
}
