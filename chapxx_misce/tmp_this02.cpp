#include <iostream>
using namespace std;


class MyClass 
{
private:  
int data1, data2;

public:
  MyClass(int data1, int data2) 
  {
    this->data1 = data1;
    this->data2 = data2;
  }

  /* Return by value
     MyClass operator = ( MyClass& c ) {
     this->data1 = c.data1;
     this->data2 = c.data2;
     return MyClass(100, 200);
     }
  */
  
  // Return by reference: '=' operator overloading 
  MyClass& operator=(MyClass& c) 
  { this->data1 = c.data1;
    this->data2 = c.data2;
    return *this;
  }
  
  void Print() { cout << data1 << ", " << data2 << endl; }
};




int main() 
{
  MyClass obj(100, 200);
  obj.Print();

  return 0;
}
