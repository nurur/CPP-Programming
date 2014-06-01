// Example : 10.1
// Self-test Exercise 10.1, 10.2, 10.3, 10.4

#include <iostream>
using namespace std;


int main()
{
  int *p1, *p2;

  // check: p1 = p2
  p1 = new int(100);
  p2 = new int(200);
  cout << *p1 << " " << *p2 << endl; 
  cout <<  p1 << " " <<  p2 << endl; 
  
  p1 = p2;
  cout << *p1 << " " << *p2 << endl; 
  cout <<  p1 << " " <<  p2 << endl; 

  *p1 = 300;
  cout << *p1 << " " << *p2 << endl; 
  cout << endl;

  delete p1;
  delete p2;



  // check: *p1 = *p2
  p1 = new int(101);
  p2 = new int(202);
  cout << *p1 << " " << *p2 << endl; 
  cout <<  p1 << " " <<  p2 << endl; 

  *p1 = *p2;
  cout << *p1 << " " << *p2 << endl; 
  cout <<  p1 << " " <<  p2 << endl; 
  cout << endl;

  delete p1;
  delete p2;

  return 0;
}
