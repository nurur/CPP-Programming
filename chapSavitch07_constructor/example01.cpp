// Example: 7.1
// Class with Constructors

#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


class dayOfYear
{
public:
  dayOfYear();
  //initialize month and day to 0

  dayOfYear(int monthValue);
  //initialize month to argument
 
  dayOfYear(int monthValue, int dayValue);
  //initialize month and day to arguments 

  void input();
  void output();
  int getMonthNum();
  int getDayNum();


private:
  int month;
  int day;
  void testDate();
};

dayOfYear :: dayOfYear() 
{
  month = 1; 
  day   = 1; 
}

dayOfYear :: dayOfYear(int monthValue) 
{ 
  month = monthValue;
  day   = 1;
  testDate();
}

dayOfYear :: dayOfYear(int monthValue, int dayValue) 
{ 
  month = monthValue;
  day   = dayValue; 
  testDate(); 
}

void dayOfYear :: input()
{
  ;
}

void dayOfYear :: output()
{
  cout << "month: " << month << ", day: " << day << endl;
}


void dayOfYear :: testDate()
{
  if ( (month < 1) || (month > 12) ) 
    {
      cout << "Illegal month value.\n";
      exit(1);
    }

  if ( (day < 1) || (day > 31) ) 
    {
      cout << "Illegal day value.\n";
      exit(1);
    }
}




int main()
{
  // Default constructor, auxilary constructors 
  cout << "Basic call to the constructors  : " << endl;
  dayOfYear date1(2,21), date2(5), date3;                 
  cout << "Initialized dates:\n";
  date1.output(); cout << endl;
  date2.output(); cout << endl;
  date3.output(); cout << endl;


  // Explcit call to the constructor
  cout << "Explcit call to the constructors: " << endl;
  dayOfYear holiday; 
  holiday = dayOfYear(10,31);             
  cout << "Dates reset to the follwoing:\n";
  holiday.output(); cout << endl;

  holiday = dayOfYear(10);             
  cout << "Dates reset to the follwoing:\n";
  holiday.output(); cout << endl;

  holiday = dayOfYear();             
  cout << "Dates reset to the follwoing:\n";
  holiday.output(); cout << endl;

  return 0;
}
