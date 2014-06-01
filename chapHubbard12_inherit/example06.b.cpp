// Example: 12.12
// Prevention of Memory Leaks 
// With Virtual Destructor 


#include <iostream>
using namespace std;


class X
{
public:
  X()          { p = new int[2]; cout << " X(). "; }
  virtual ~X() { delete [] p;    cout << "~X().\n";}

private:
  int* p;
};


class Y : public X
{
public:
  Y()         { q = new int[1023]; cout << " Y(): Y::q = " << q << ". ";}
 virtual ~Y() { delete [] q;       cout << "~Y(). ";}

private:
  int* q;
};





int main()
{
  cout << endl;

  for (int i=0; i<8; i++)
 { 
   X* r = new Y; 
   delete r;
 } 
  
  cout << endl;
  return 0;
}
