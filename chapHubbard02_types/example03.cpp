// sizeof operator in C++
/*                                    */
/* fundamental types: (bool, char, int), float */
/* modifiers */ 
/* signedness: signed, unsigned       */
/* size      : short, long, long long */
/*                                    */
/* use          char for character data (supported by the implementation) */
/* use unsigned char for raw data, eg. data transmitted over a comms link*/



#include <iostream>
using namespace std;


int main ()
{

  cout << "Number of bytes used:"  << endl;
  cout << "\t              char: " <<          sizeof(char) << endl;
  cout << "\t             short: " <<         sizeof(short) << endl;
  cout << "\t               int: " <<           sizeof(int) << endl;
  cout << "\t              long: " <<          sizeof(long) << endl;
  cout << endl;

  cout << "\t unsigned     char: " <<  sizeof(unsigned char) << endl;
  cout << "\t unsigned    short: " << sizeof(unsigned short) << endl;
  cout << "\t unsigned      int: " <<   sizeof(unsigned int) << endl;
  cout << "\t unsigned     long: " <<  sizeof(unsigned long) << endl;

  cout << "\t   signed     char: " <<    sizeof(signed char) << endl;
  cout << endl;

  cout << "\t             float: " <<          sizeof(float) << endl;
  cout << "\t            double: " <<         sizeof(double) << endl;
  cout << "\t       long double: " <<    sizeof(long double) << endl;

  return 0;
}
