// Example 11.5 
// Namespace


#include <iostream>
using namespace std;


namespace Space1
{
  void func1()    { cout << "Hello from func1 ... ... ......" << endl; }
  void greeting() { cout << "Hello from namespace Space1 ..." << endl; }
}


namespace Space2
{
  void func2()    { cout << "Hello from func2 ... ... ......" << endl; }
  void greeting() { cout << "Greetings from namespace Space2" << endl; }
}



void bigGreeting() { cout << "A Big Global Hello" << endl; }




int main()
{
  {
    using namespace Space1;       // turn-on namespace 1
    greeting();
  }
  
  {
    using namespace Space2;       // turn-on namespace 2
    greeting();
  }
  cout << endl;



  { using Space1 :: greeting; 
    greeting(); 
  }
  { using Space2 :: greeting; 
    greeting(); 
  }
  cout << endl;


  Space1 :: greeting();
  Space2 :: greeting();
  cout << endl;


  Space1 :: func1();
  Space2 :: func2();
  cout << endl;


  bigGreeting();                  // global namespace


  return 0;
}
