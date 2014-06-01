// Example: Self-Test Exercise 8 
// Namespace


#include <iostream>
using namespace std;


namespace Hello
{
  void message() { cout << "This is namespace Hello   " << endl; }
}


namespace GoodBye
{
  void message() { cout << "This is namespace Goodbye " << endl; }
}


void message();




int main()
{
  using GoodBye :: message;

  {
    using Hello :: message;
    message();
    GoodBye :: message();
  }

  message();

  return 0;
}
