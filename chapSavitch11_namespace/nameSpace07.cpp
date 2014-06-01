// Example:
// Nested Namespace 




#include <iostream>
using namespace std;

// nested namespace 
namespace NSOuter
{
  void message()
  { cout << "Outer" << endl; }
  
  namespace NSInner
  {
    void message()
    { cout << "Inner" << endl; }
  }
}




int main()
{
  //nested namespace
  NSOuter :: message();
  NSOuter :: NSInner :: message();
  using namespace NSOuter;
  NSInner :: message();

  return 0;
}
