// Example: 11.1, 11.2, 11.3
// Class DigitalTime
// Application File : Main program  


#include "dtimev1.hpp"
#include <iostream>
using namespace std;



int main()
{
  DigitalTime clock, oldClock;
  cout << "You may write midnight as either 0:00 or 24:00\n"
       << "but I will always write it as 0:00.\n"
       << "Enter the time in 24-hour notation: ";
  cin  >> clock;
  cout << endl;


  oldClock = clock;
  clock.advance(15);
  
  if ( clock == oldClock )
    cout << "Something is wrong.";
  
  cout << "15 minutes later the time will be " 
       << clock << endl;

  
  clock.advance(2,15);
  cout << "2 hours and 15 minutes later the time will be " 
       << clock << endl;


  cout << endl;
  return 0;
}

