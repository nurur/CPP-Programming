// Example: 11.1, 11.2, 11.3
// Class DigitalTime
// Interface File: Declares member functions and overloaded operators 


#ifndef DTIME_HPP
#define DTIME_HPP


#include <cctype>
#include <cstdlib>
#include <iostream>
using namespace std;


// Class Declaration ************************************ 
class DigitalTime
{
friend istream& operator>>(istream& in, DigitalTime& theObject);
friend ostream& operator<<(ostream& out, const DigitalTime& theObject);
friend bool operator==(const DigitalTime& time1, 
		       const DigitalTime& time2);

public:
  DigitalTime();
  DigitalTime(int theHour, int theMinute);

  int   getHour() const;
  int getMinute() const;
  void advance(int minutesAdded); // change the time minutesAdded minutes later 
  void advance(int hoursAdded, int minutesAdded); 
  // change the time to hoursAdded hour plus minutesAdded minutes late

private:
  int hour;
  int minute;

  static void   readHour(int& theHour);
  // input read from the keyboard, e.g., as 9:45 or 14:25
  // theHour has been set to the hour part of the time
  // the colon has been discarded and the next input to be read is the minute

  static void readMinute(int& theMinute);
  // reads theMinute from the keyboard after readHour has read the hour 

  static int digitToInt(char c);
  // c is one of the digits '0' to '9'
  // returns integer for the digit, e.g., digit('3') return 3  
}; 

#endif  //DTIME_HPP





// Class Definition ************************************ 
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

void DigitalTime :: advance(int hoursAdded, int minutesAdded) 
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
{
  return (time1.hour == time2.hour && time1.minute == time2.minute);
}


void DigitalTime :: readHour(int& theHour)
{
  char c1, c2;
  cin >> c1 >> c2;
  
  if ( !( isdigit(c1) && (isdigit(c2) || c2 == ':') ))
    {
      cout << "Error1: Illegal input to readHour\n";
      exit(1);
    }
  
  if ( isdigit(c1) && c2 == ':' )   // single digit hour
    { 
      theHour = DigitalTime :: digitToInt(c1);
    }
  else                              // double digit hour
    {
      theHour = DigitalTime :: digitToInt(c1)*10 
	      + DigitalTime :: digitToInt(c2);
      
      cin >> c2; //discard ':'
      if ( c2 != ':' )
	{
	  cout << "Error2: Illegal input to readHour\n";
	  exit(1);
	} 
    }
  
   if ( theHour == 24 ) theHour = 0;
   if ( theHour < 0 || theHour > 23 )
     {
       cout << "Error: Illegal input to readHour\n";
       exit(1);
     } 
}


void DigitalTime :: readMinute(int& theMinute)
{
  char c1, c2;
  cin >> c1 >> c2;
  
  if ( !( isdigit(c1) && isdigit(c2) ) )
    {
      cout << "Error: Illegal input to readHour\n";
      exit(1);
    }
  
  theMinute =  DigitalTime :: digitToInt(c1)*10 
            +  DigitalTime :: digitToInt(c2);

  if ( theMinute < 0 || theMinute > 59 )
    {
      cout << "Error: Illegal input to readHour\n";
      exit(1);
    } 
}


int DigitalTime :: digitToInt(char c)
{
  //cout << ( static_cast<int>(c) - static_cast<int>('0') );
  return ( static_cast<int>(c) - static_cast<int>('0') );
}




// Main Program ************************************ 
int main()
{
  DigitalTime clock, oldClock;
  cout << "You may write midnight as either 0:00 or 24:00\n"
       << "but I will always write it as 0:00." << endl;
  cout << "Enter the time in 24-hour notation: ";
  cin  >> clock;
  cout << endl;


  oldClock = clock;
  clock.advance(15);   // advancing by minute

  if ( clock == oldClock )
    cout << "Something is wrong.";
  
  cout << "15 minutes later the time will be " 
       << clock << endl;
  cout << endl;
  

  clock.advance(2,15); // advancing by hour and minute 
  cout << "2 hours and 15 minutes later the time will be " 
       << clock << endl;


  cout << endl;
  return 0;
}




