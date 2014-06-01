// Date.hpp
// Class Date

 
#include <iostream>
using namespace std;


class Date
{
  friend istream& operator>>(istream&, Date&);       // input stream operator
  friend ostream& operator<<(ostream&, const Date&); // output stream operator
  
public:
  Date(int, int, int);             // constructor 
  void setDate(int, int, int);     // member function 
  
private:
  int month;
  int day;
  int year;
};



// constructor
Date :: Date(int m=0, int d=0, int y=0) 
  : month(m), day(d), year(y) { }

// member function 
void Date :: setDate(int m, int d, int y)
{ month = m; day = d; year = y;}


// friend function: input stream operator
istream& operator>>(istream& istr, Date& x)
{ 
  istr >> x.month >> x.day >> x.year;
  return istr;
}

// friend function: output stream operator
ostream& operator<<(ostream& ostr, const Date& x)
{ 
  const char* monthName[12] = {"January","February","March","April", 
				"May", "June", "July", "August",
				"September","October","November","December"};
  ostr << monthName[x.month] << ", " << x.day << ", " << x.year;
  return ostr;
}
