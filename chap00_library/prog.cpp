
#include <iostream>
#include <math.h>
using namespace std;


void ctest1(int *);
void ctest2(int *);


int main()
{
  int x;
  ctest1(&x);

  cout << "Valx=%d" << x << endl;
  
  return 0;
}
