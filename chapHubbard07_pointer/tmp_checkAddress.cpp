// Example 
// Addresses of objects 
// static and dynamic memory allocation


#include <iostream>
using namespace std;


int main ()
{
  cout << "Addresses of various objects ...  " << endl;

  bool   sa   = false;
  short  sb   = 22;
  int    sc   = 44;
  float  sd   = 2.0;
  double se   = 4.0;
  string sf   = "ABCDE";
  float  sr[5]= {0.};
  cout << endl;
  cout << "Using static memory allocation  : " << endl;
  cout << "bool   : " << &sa << endl;
  cout << "short  : " << &sb << endl;
  cout << "int    : " << &sc << endl;
  cout << "float  : " << &sd << endl;
  cout << "double : " << &se << endl;
  cout << "string : " << &sf << endl;
  cout << "array  : " << &sr << endl;


  bool*   da   = new bool(false);
  short*  db   = new short(22);
  int*    dc   = new int(44);
  float*  dd   = new float(2.0);
  double* de   = new double(4.0);
  string* df   = new string("ABCDE");
  float*  dr   = new float[5];
  cout << endl;
  cout << "Using dynamic memory allocation : " << endl;
  cout << "bool   : " << da << endl;
  cout << "short  : " << db << endl;
  cout << "int    : " << dc << endl;
  cout << "float  : " << dd << endl;
  cout << "double : " << de << endl;
  cout << "string : " << df << endl;
  cout << "array  : " << dr << endl;

  return 0;
}
