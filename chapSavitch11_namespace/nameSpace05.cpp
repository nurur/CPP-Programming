// Example:
// Nested Namespace 
// Unnamed Namespace



#include <iostream>
using namespace std;


// nested namespace 
namespace A
{
  int i;

  namespace B 
  {
    void a() { i++; }
    int j;
    void b() { j++; }
  }
}


// unnamed namespace
namespace 
{
  int i = 2;
}




int main()
{
  //unnamed namespace
  cout << i << endl; 



  //nested namespace
  A :: i = 2;         //ok
  A :: B :: j = 11;   //ok
  
  using namespace A;
  B :: a(); 
  cout << A::i << endl;
  B :: b();
  cout << B::j << endl;
  


  return 0;
}
