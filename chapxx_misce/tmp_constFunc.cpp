// Example:
// Calling "constant function" from "constant class" 


#include <iostream>
using namespace std;


class TwoNum
{
public:
  TwoNum();
  TwoNum(const TwoNum&);
  TwoNum(int aa, int bb) : a(aa), b(bb) { }

  int First()  {cout<< a << endl; return a;}
  int Second() const {cout << b << endl; return b;}

private:
  int a, b;
};




int main()
{
  const TwoNum x(2,3);
  //int y =  x.First();
  int z = x.Second();
  cout << endl;

  TwoNum a(2,3);
  int b =  a.First();
  int c = a.Second();


  /* if TwoNum is declared "const" the only the const functions 
     can be called
  */

  return 0;
}
