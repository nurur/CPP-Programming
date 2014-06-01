// Example: 11.1, 11.2, 11.3
// Class DigitalTime
// Interface File: Declares member functions and overloaded operators 
// Version 2: namespace and unnamed namespace


#ifndef DTIMEV2_HPP
#define DTIMEV2_HPP

#include <cstdlib>
#include <iostream>
using namespace std;



namespace dtimeRahman 
{
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
}; 

}       //namespace dtimeRahman
#endif  //DTIME_HPP
