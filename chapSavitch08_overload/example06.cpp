// Example
// Self-test Exercise 11


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


class Percent
{
  friend bool operator==(const Percent& first, const Percent& second);
  friend bool operator<(const Percent& first, const Percent& second);
  friend istream& operator>>(istream& istr, Percent& aPercent);   
  friend ostream& operator<<(ostream& ostr, const Percent& aPercent); 
  
public:
  Percent();
  
private:
  int value;
};



Percent :: Percent() { value = 0.0; }

istream& operator>>(istream& inpstr, Percent& aPercent)
{
  char percentSign;
  inpstr >> aPercent.value;
  inpstr >> percentSign;
  return inpstr;
}   

ostream& operator<<(ostream& outstr, const Percent& aPercent)
{
  outstr << aPercent.value << '%';
  return outstr;
}   



int main()
{
  Percent myPercent;
  cout << "Enter a number: ";
  cin >> myPercent; 
  cout << "my percent is : " << myPercent << endl;
  
  return 0;
}
