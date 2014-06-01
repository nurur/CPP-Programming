// Example: 13.3
// Class Template 
// Stack Class, Max Class


#include <iostream>
using namespace std;


//Stack Class
template <class T>
class Stack
{
public:
  Stack();
  Stack(const Stack& s)     : size(s.size), top(s.top) { }
  Stack(int s=10, int t=-1) : size(s), top(t) { a = new T[size]; }
 ~Stack() { delete[] a; }
  
  void push(const T& item) { a[++top] = item; }
  T pop() { return a[top--]; }
  
  bool isEmpty() const { return top == -1; }
  bool  isFull() const { return top == (size-1); }
  
private:
  int size; //size of array
  int top;  //top of stack 
  T* a;     //data array to hold stack items
};



// Class Pair
template <class T>
class myPair 
{
public:
  myPair(){};
  myPair(T first, T second) : a(first), b(second) { }
  T GetMax();

private:
  T a,b;
};

template <class T>
T myPair<T> :: GetMax ()
{
  T Val;
  Val = (a>b ? a : b);
  return Val;
}




int main()
{
  Stack<int>    intStack1(5);  // size  5
  Stack<int>   intStack2(10);  // size 10
  Stack<char>  charStack(10);  // size 10
   
  intStack1.push(77);          // intStack1: size  5, top 0 (1 items)

  intStack2.push(22);          // intStack2: size 10, top 1 (2 items)
  intStack2.push(44);

  charStack.push('A');         // charStack: size 10, top 2 (3 items)
  charStack.push('E');
  charStack.push('K');


  cout << intStack2.pop() << endl;
  cout << intStack2.pop() << endl;
  if( intStack2.isEmpty() ) cout << "intStack2 is empty" << endl;
  
  cout << endl;
  return 0;
}
