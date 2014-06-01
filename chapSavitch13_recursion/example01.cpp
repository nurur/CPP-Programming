// Example: 13.1
// Recursive function 


#include <cstdlib>
#include <iostream>
using namespace std;


void writeVertical( int n)
{
  if (n < 10)
    {
      cout << n << endl;
    }
  else
    {
      writeVertical( n/10 );
      cout << ( n%10 ) << endl;
    }
}




int main()
{
  cout << "writeVertical(1)" << endl;
  writeVertical(1);
  cout << endl;


  cout << "writeVertical(12)" << endl;
  writeVertical(12);
  cout << endl;


  cout << "writeVertical(123)" << endl;
  writeVertical(123);
  
  return 0;
}
