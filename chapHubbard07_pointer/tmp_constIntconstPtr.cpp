#include <iostream>
using namespace std;



int main()
{
  int n1, n2;
  n1=10;
  n2=15;

  int* pn       = &n1;
  cout << pn << " " << *pn << " " << &pn << endl;

  //int* const pn = &n1;   //const address assigend to the pointer
  //pn = &n2;              //Error! address is not going to be changed!

  //const int* pn = &n1;   //const integer assigend to the pointer
  //*pn = n2;              //Error! integer is not going to be changed!


  //const int* const pn = &n1; //const address, const int assigend to the ptr
  //pn  = &n2;
  //*pn = n2;   

  return 0;
}
