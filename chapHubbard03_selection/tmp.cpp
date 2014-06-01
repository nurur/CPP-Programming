

#include <iostream>
using namespace std;


int main()
{
  int p = 1;
  cout << !p << !!p << !!!p << endl;



  int x = 1;
  int y = 0;

  if (x == 0)
    {
      if(y == 0) cout << "both are 0" << endl;
    }
  else cout << "x is not 0" << endl;

  if (x > 2)
    {
      if(x < 6) cout << "OK" << endl;
    }
  else cout << "NG 1" << endl;

  if (x > 2)
    {
      if(x < 6) cout << "OK" << endl;
      else cout << "NG 2" << endl;
    }



  int m = ( x<y ? -1 : (x==y ? 0:1) );
  cout << m << endl;

  return 0;
}
