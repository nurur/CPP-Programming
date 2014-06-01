//
// Note:
// Const Class can call only Const Member Function 


#include <iostream>
using namespace std;


class TwoNum
{
public:
  TwoNum();
  TwoNum(int a, int b) : aa(a), bb(b) { }
  
  int  First()       { return aa; }
  int Second() const { return bb; }

private: 
  char cc;
  int aa, bb;
};




int main()
{
  // check 
  TwoNum x(17,32);
  int a = x.First();   // Legal
  int b = x.Second();  // Legal

  cout << a << " " << b << endl;
  cout << b << endl;
  cout << endl;



  // check 
  const TwoNum y(17,32);
  
  //int c = y.First();   // Illegal
  int d = y.Second();    // Legal

  //cout << c << " " << d << endl;
  cout << d << endl;


  return 0;
}
