// Example: 7.17
// Arrays of Pointers
// Pointers to Pointers


#include <iostream>
using namespace std;


int main()
{
  // check 
  // Arrays of pointers
  double *p[4];
  p[0] = new double(1.1);
  p[1] = new double(2.2);
  p[2] = new double(3.3);
  p[3] = new double(4.4);

  for (int i=0;i<4;i++)
    delete[] p[i];
  

  double *q[4];
  double a1 = 1.1; 
  double a2 = 2.2; 
  double a3 = 3.3; 
  double a4 = 4.4; 
  q[0] = &a1;
  q[1] = &a2;
  q[2] = &a3;
  q[3] = &a4;
  for (int i=0;i<4;i++)
    cout << *q[i] << " ";
  cout << endl;


  // check 
  // Pointers to Pointers
  char c = 't';
  cout<< c << endl;

  char  *pc    =   &c;
  char **ppc   =  &pc;
  char ***pppc = &ppc;

  ***pppc = 'w';

  cout<< c << endl;

  return 0;
}
