#include <iostream>
using namespace std;



int main()
{
  int  n = 44;
  int* p = &n;
  cout << &n << "  " <<  n << endl;
  cout << p << "  " << *p << "  " << &p << endl;

  int* q = new int(44);
  cout << q << "  " << *q << "  " << &q << endl;

  delete q;
  cout << q << "  " << *q << "  " << &q << endl;

  return 0;
}
