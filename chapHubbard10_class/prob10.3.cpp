// Problem 10.3 
// Time Class 


#include <cmath>
#include <iostream>
using namespace std;


class Time
{
public :
  Time(int h=0, int m=0, int s=0): hr(h), min(m), sec(s){}; 
                                                    // default constructor
  Time(const Time& T);                              // copy constructor

  int   hour() { return hr;  }                      // access function
  int minute() { return min; }
  int second() { return sec; }

  int advanceHour(int&,int&,int&);
  int advanceMint(int&);
  int advanceSecd(int&);
  void   reset();
  void   print();

private:
  int hr;
  int min;
  int sec;
};



int main()
{ 
  int choice, t;
  Time T(1,20,30);
  
  cout << "Current time : "; T.print(); cout << endl; 
  cout << "Do you want to advance hour, minute, or second?       "; 
  cout << endl;
  cout << "Enter 1, 2, or 3 for hour, min, or sec, respectively: "; 
  cin >> choice;
  cout << endl;

  if (choice == 1) 
    {
      cout << "advancing by hour  " << endl;
      t = T.hour() + 1;
      cout << t << endl; 
    }
  else if (choice == 2)
    {
      cout << "advancing by minute" << endl;
      t = T.minute() + 1;
      cout << t << endl;    
    }
  else 
    {
      cout << "advancing by second" << endl;
      t = T.second() + 1;
      cout << t << endl;     
    }
  
  
  T.reset();
  cout << "Current time : "; T.print(); cout << endl; 

  cout << endl;
  return 0;
}



int Time :: advanceHour(int& h, int& m, int& s)
{ return (hr = h+1, min =m, sec=s); 
}
int Time :: advanceMint(int& m)
{ return min = m + 1; }
int Time :: advanceSecd(int& s)
{ return sec = s + 1; }


void Time :: reset()
{ cout << "Resetting time ..."; cout << endl;
  hr = 0, min = 0, sec = 0;
}

void Time :: print()
{cout << "hour: " << hr << "  min: " << min << "  sec: " << sec;}

