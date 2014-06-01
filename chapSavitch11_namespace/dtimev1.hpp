// Example: 11.1, 11.2, 11.3
// Class DigitalTime
// Interface File: Declares member functions and overloaded operators 
// Version 1: no use of namespace 


#ifndef DTIMEV1_HPP
#define DTIMEV1_HPP

#include <cstdlib>
#include <iostream>
using namespace std;



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
