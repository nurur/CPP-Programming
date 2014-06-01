//Example: 12.12, chap 12 (C++, J Hubbard)
// Virtual Destructors
// Memory Leaks 


#include <iostream>
using namespace std;


class X
{
public:
  X() { p = new int[2]; cout << " X(). ";  }
 ~X() { delete [] p;    cout << "~X(): Deleting X().\n";}

private:
  int* p;
};


class Y : public X
{
public:
  Y() { q = new int[1025]; cout << " Y(): Y::q = " << q << ". ";}
 ~Y() { delete [] q;       cout << "~Y(). \n";}

private:
  int* q;
};





int main()
{
  cout << endl;

  // No memory leaks
  for (int i=0; i<8; i++)
 { 
   X* r = new X; 
   delete r;       // delete call frees X 
 } 
  cout << endl;


  // Obvious memory leaks
  for (int i=0; i<8; i++)
 { 
   X* r = new Y;   // delete call only frees X but not Y!
   delete r;
 } 
  

  return 0;
}
