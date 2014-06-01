// EXAMPLE 7.11: 
// Examining the addresses of array elements Loop over pointer 


#include <iostream>
using namespace std;


int main ()
{
  int SIZE;


  // part 1: "char" array
  char c[] = {'a', 'b', 'c', 'd', 'e'};
  cout << "c = " << c << ", *c = " << *c << endl;
  cout << endl;  
  
  char* p;
    p = c;
    SIZE = sizeof(c);           //SIZE for type "char"

  for ( ; p < c + SIZE; p++)
    cout << "p = " << p << ", *p = " << *p << endl;
  cout << endl;  

  

  // part 2: "short" array 
  short a[] = {22, 33, 44, 55, 66};
  
  cout << "a = " << a << ", *a = " << *a << endl;
  cout << endl;  

  short* q;
  SIZE = sizeof(a)/sizeof(*a);  //SIZE for type "short"

  for (q = a; q < a + SIZE; q++)
    cout << "q = " << q << ", *q = " << *q << endl;
  cout << endl;  



  // priorities
  char a1,a2,a3;
  char* bb;
  char cc[] ={'a','b','c','d','e'};

  bb = cc;        // bb = cc[0]
  a1 = *bb++;   // assign *bb first to a1 (cc[0]) and then do incremement 
  cout << a1 << endl;

  a2 = (*bb)++;  // increment (*bb) first to the next value and then assign
  cout << a2 << endl; 

  a3 = *(bb++);  // increment (bb) first to the next value and then assign
  cout << a3 << endl;
  

  cout << endl;    
  return 0;
}

