// Example : 4.26, 4.27, 4.28
// Generating Pseudo-Random Numbers
 

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


 

int main()
{
  // Setting Seed Interactively 
  //unsigned seed;
  //cin >> seed;


  // Setting Seed from System Clock
  unsigned seed = time(NULL);
  cout << "seed : " << seed << endl;
  cout << endl;

  srand(seed);
  for (int i=0; i<10; i++) 
    cout << rand() % 10 << endl;
  cout << endl;
    
  cout << "cstdlib: RAND_MAX " << RAND_MAX << endl;
  cout << endl;


  // Random Number in a Given Range
  cout << "Random Number in a Given Range" << endl;
  int max   = 100;
  int min   = 1;
  int range = max - min + 1;
  cout << "The range : " << min << "  " << max << endl;
  for (int i=0; i<10; i++) 
    cout <<   (rand() % range + min ) << endl;

  return 0;
}
