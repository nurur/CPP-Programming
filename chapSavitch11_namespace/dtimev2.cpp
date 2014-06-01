// Example: 11.1, 11.2, 11.3
// Class DigitalTime
// Implementation File: Defines member functions and overloaded operators
// Version 2: using namespace and unnamed namespace 


#include "dtimev2.hpp"
#include <cctype>
#include <cstdlib>
#include <iostream>
using std :: istream;
using std :: ostream;
using std :: cout;
using std :: cin;
using std :: endl;

namespace 
{
int digitToInt(char c)
{ return ( static_cast<int>(c) - static_cast<int>('0') ); }

void readMinute(int& theMinute)
{
  char c1, c2;
  cin >> c1 >> c2;
  
  if ( !( isdigit(c1) && isdigit(c2) ) )
    {
      cout << "Error: Illegal input to readHour\n";
      exit(1);
    }
  
  theMinute = digitToInt(c1)*10 + digitToInt(c2);

  if ( theMinute < 0 || theMinute > 59 )
    {
      cout << "Error: Illegal input to readHour\n";
      exit(1);
    } 
}


void readHour(int& theHour)
{
  char c1, c2;
  cin >> c1 >> c2;
  
  if ( !( isdigit(c1) && (isdigit(c2) || c2 == ':') ))
    {
      cout << "Error: Illegal input to readHour\n";
      exit(1);
    }
  
  if ( isdigit(c1) && c2 == ':' )
    { 
      theHour = digitToInt(c1); 
    }
  else
    theHour = digitToInt(c1)*10 
            + digitToInt(c2);


  cin >> c2; //discard ':'
  if ( c2 != ':' )
    {
      cout << "Error: Illegal input to readHour\n";
      exit(1);
    } 

   if ( theHour == 24 ) theHour = 0;
   if ( theHour < 0 || theHour > 23 )
     {
       cout << "Error: Illegal input to readHour\n";
       exit(1);
     } 
}
} //namespace




namespace dtimeRahman
{
DigitalTime :: DigitalTime() { hour = 0; minute = 0; }

DigitalTime :: DigitalTime(int theHour, int theMinute)
{
  if (theHour < 0 || theHour > 24 || theMinute < 0 || theMinute > 59)
    {  cout << "Illegal argument to DigitalTime construcntor";
       exit(1);
    }
  else 
    { hour   = theHour;
      minute = theMinute;
    }

  if (hour == 24) hour = 0; //Standardize midnight as 0.00
}

int DigitalTime ::   getHour() const { return hour;   }
int DigitalTime :: getMinute() const { return minute; }


void DigitalTime :: advance(int minutesAdded) 
{
  int grossMinutes = minute + minutesAdded;
  minute = grossMinutes % 60;
  int hourAdjustment = grossMinutes / 60;
  hour   = (hour +  hourAdjustment) % 24;
}

void DigitalTime :: advance(int minutesAdded, int hoursAdded) 
{
  hour   = (hour +  hoursAdded) % 24;
  advance(minutesAdded);
}

// using iostream : istream
istream& operator>>(istream& istr, DigitalTime& theObject)
{
  DigitalTime :: readHour(theObject.hour);
  DigitalTime :: readMinute(theObject.minute);
  return istr;
}

// using iostream : ostream
ostream& operator<<(ostream& ostr,  const DigitalTime& theObject)
{
  ostr << theObject.hour << ':';
  if ( theObject.minute < 10 ) ostr << '0';
  ostr << theObject.minute;
  return ostr;
}

bool operator==(const DigitalTime& time1, const DigitalTime& time2) 
{ return (time1.hour == time2.hour && time1.minute == time2.minute); }
} //namespace dtimeRahman


