// Example:
// Namespace 
// Unnamed Namespace


#include <iostream>
using namespace std;


namespace Sally 
{ void sayHello() { cout << "Hello from Sally  "; } 
}

namespace  
{ void sayHello() { cout << "Hello from unnamed"; } 
}


int main()
{

  {
    sayHello(); 
  }
  cout << endl;

  sayHello();

  cout << endl;
  return 0;
}
