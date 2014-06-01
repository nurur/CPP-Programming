// Problem 10.1 
// Stack Class 


#include <iostream>
using namespace std;

#define STACKOVERFLOW  -1
#define STACKUNDERFLOW -2


class Stack
{
public :
  Stack();                                                 // default
  Stack(const Stack&);                                     // copy 
  Stack(int s = 100) : size(s),top(-1) { a = new int[size]; } // constructor
 ~Stack() {delete [] a;}                                   // destructor 

  void push(const int& item) { a[++top] = item; }
  int  pop() { return a[top--]; }

  bool isEmpty() const { return top == -1; }
  bool isFull()  const { return top == (size-1); }

private:
  int size;  // size of array
  int top;   // top of stack 
  int* a;    // data array to hold stack items
};



int main()
{
  Stack S;
  cout<< endl;

  S.push(9);
  S.push(8);
  S.push(7);
  S.push(6);
  S.push(5);
  S.push(4);
  S.push(3);
  S.push(2);
  S.push(1);
  S.push(0);


  S.pop();

  cout << endl;
  return 0;
}

