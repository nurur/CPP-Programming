// use pointer, eample 1

#include <iostream>
using namespace std;


void double_it1(int *p);
int double_it2(int n);


int main()
{
  int a = 5, b = 6;   // assign numbers

  cout << endl;

  //print the assigned number
  cout << "value of a before doubling is :" << a << endl;
  cout << "value of b before doubling is :" << b << endl;

  cout << endl;

  cout << "Case 1 : pointer passed to a function" << endl; 
  //action of pointer
  double_it1(&a);    //pass address of a
  double_it1(&b);    //pass address of b

  //print changed number
  cout << "value of a after doubling is :" << a << endl;
  cout << "value of b after doubling is :" << b << endl;

  cout << endl;

  cout << "Case 2: argument passed to a function" << endl; 
  int c = 5, d = 6;   // assign numbers

  //action of function 
  double_it2(c);    //pass address of a
  double_it2(d);    //pass address of b

  //print changed number
  cout << "value of a after doubling is :" << c << endl;
  cout << "value of b after doubling is :" << d << endl;

  cout << endl;
  return 0;
}



// subroutine using 'void'
void double_it1(int *p){
  *p = *p * 2;
}


// subroutine using 'return'
int double_it2(int n){

  //cout << "before: " << n <<endl;
  n = n * 2;  
  //cout << "after: " << n << endl;
  
  return n;

}


