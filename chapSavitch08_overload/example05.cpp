// Example: 8.5
// Class Money 
// Overloading operators as friend functions of the class


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


class Money
// Class for amounts of money in US currency
{
  // operator overloading 
  // binary (+,-,*,/) operator
  // relational (==, >=, <=, >, <, !=) operator
  // unary (negation, -) operator
  // insertion(<<) and extraction(>>) operator
  friend const Money operator+(const Money& amount1, const Money& amount2);
  friend const Money operator-(const Money& amount1, const Money& amount2);
  friend const Money operator*(const Money& amount1, const Money& amount2);
  friend const Money operator/(const Money& amount1, const Money& amount2);
  friend bool operator==(const Money& amount1, const Money& amount2);
  friend bool operator>(const Money& amount1, const Money& amount2);
  friend bool operator<(const Money& amount1, const Money& amount2);
  friend const Money operator-(const Money& amount); 
  friend istream& operator>>(istream& istr, Money& amount);   
  friend ostream& operator<<(ostream& ostr, const Money& amount); 
  
public:
  Money();
  Money(int theDollars);
  Money(double amount);
  Money(int theDollars, int theCents);

  // member functions
  //int   getDollars() const;
  //int     getCents() const;
  //double getAmount() const;
  
private:
  int dollars;
  int cents;

  int dollarsPart(double amount) const; 
  int   centsPart(double amount) const;
  int       round(double number) const;
};


const Money operator+(const Money& amount1, const Money& amount2) 
{
  int allCents1   = amount1.cents + amount1.dollars * 100;
  int allCents2   = amount2.cents + amount2.dollars * 100; 
  int addAllCents = allCents1 + allCents2;
  int absAllCents = abs(addAllCents);
  
  int finalDollars= absAllCents / 100;
  int finalCents  = absAllCents % 100;
  
  if (addAllCents < 0)
    {
      finalDollars= -finalDollars;
      finalCents  = -finalCents;
    }

  return Money(finalDollars, finalCents); 
}


const Money operator-(const Money& amount1, const Money& amount2)
{
  int allCents1   = amount1.cents + amount1.dollars * 100;
  int allCents2   = amount2.cents + amount2.dollars * 100; 
  int diffAllCents= allCents1 - allCents2;
  int absAllCents = abs(diffAllCents);
  
  int finalDollars= absAllCents / 100;
  int finalCents  = absAllCents % 100;
  
  if (diffAllCents < 0)
    {
      finalDollars= -finalDollars;
      finalCents  = -finalCents;
    }

  return Money(finalDollars, finalCents); 
}

//Multiplication operator 
const Money operator*(const Money& amount1, const Money& amount2)
{
  int allCents1   = amount1.cents + amount1.dollars * 100;
  int allCents2   = amount2.cents + amount2.dollars * 100; 
  int multAllCents= (allCents1 * allCents2);
  int absAllCents = abs(multAllCents);
  
  int finalDollars= (absAllCents/100) / 100;
  int finalCents  = (absAllCents/100) % 100;
  
  if (multAllCents < 0)
    {
      finalDollars= -finalDollars;
      finalCents  = -finalCents;
    }

  return Money(finalDollars, finalCents); 
}


//Division operator 
const Money operator/(const Money& amount1, const Money& amount2)
{
  int allCents1   = amount1.cents + amount1.dollars * 100;
  int allCents2   = amount2.cents + amount2.dollars * 100; 

  int finalDollars= (allCents1 / allCents2);
  int finalCents  = (allCents1 % allCents2);
  finalCents  = finalCents * 100 / allCents2;

  if (finalDollars < 0)
    {
      finalDollars= -finalDollars;
      finalCents  = -finalCents;
    }

  return Money(finalDollars, finalCents); 
}

//Equal to operator  
bool operator==(const Money& amount1, const Money& amount2) 
{
  return ( (amount1.dollars  == amount2.dollars)
	   && (amount1.cents == amount2.cents) );
}

//Greater than operator 
bool operator>(const Money& amount1, const Money& amount2) 
{
  return ( (amount1.dollars  > amount2.dollars)
	   && (amount1.cents > amount2.cents) );
}

//Less than operator
bool operator<(const Money& amount1, const Money& amount2) 
{
  return ( (amount1.dollars  < amount2.dollars)
	   && (amount1.cents < amount2.cents) );
}


//Unary subtraction operator 
const Money operator-(const Money& amount) 
{
  return Money(-amount.dollars, -amount.cents);
}


istream& operator>>(istream& istr, Money& amount) 
{
  char dollarSign;
  istr >> dollarSign;

  if (dollarSign != '$') // if (strcmp(dollarSign, '$') == 0)
    {
      cout << "No dollar sign in Money input. \n";
      exit(1);
    }

  double amountAsDouble;
  istr >>  amountAsDouble;

  amount.dollars = amount.dollarsPart(amountAsDouble);
  amount.cents   = amount.centsPart(amountAsDouble);

  return istr;
}   

ostream& operator<<(ostream& ostr, const Money& amount)
{
  int absDollars = abs(amount.dollars);
  int absCents   = abs(amount.cents);
  ostr << "Account balance: ";
  
  if (amount.dollars < 0 || amount.cents < 0) 
    ostr << "$";
  else 
    ostr << '$' << amount.dollars;
  
  if (absCents >= 10)
    ostr << "." << absCents << endl;
  else
    ostr << "." << '0' << absCents << endl;

  return ostr;
} 



// Constructors             **************************************
Money :: Money()
{
  dollars = 0.0; 
  cents   = 0.0;
}

Money :: Money(double amount)
{
  dollars = dollarsPart(amount);
  cents   = centsPart(amount);
}

Money :: Money(int theDollars)
{
  dollars = theDollars;
  cents   = 0.0;
}

Money :: Money(int theDollars, int theCents)
{
  if ( (theDollars < 0 && theCents > 0) ||(theDollars > 0 && theCents < 0) )
    {
      cout << "Inconsistent money data.\n";
      exit(1);
    }
  
  dollars = theDollars;
  cents   = theCents;
}



// Public member functions  **************************************
/*
double Money :: getAmount() const
{
  return (dollars + cents * 0.01);
}

int Money :: getDollars() const
{
  return dollars;
}
int Money :: getCents() const
{
  return cents;
}
*/


// Private member functions **************************************
int Money :: dollarsPart(double amount) const
{
  return static_cast<int> (amount);              //Use <cmath>
}

int Money :: centsPart(double amount) const 
{
  double doubleCents = amount * 100;
  int intCents       =  (round(fabs(doubleCents)) );
  if (amount < 0)  intCents = -intCents;

  return (intCents % 100);                      //Return the amount in 'cents' 
}

int Money :: round(double number) const 
{
  return static_cast<int> (floor (number+0.5)); //Use <cmath>
}



int main()
{
  Money baseAmount(100, 60), fullAmount;
  fullAmount = baseAmount + 25;
  //cout << fullAmount << endl;
  //fullAmount = 25 + baseAmount; 
  
  Money yourAmount, myAmount(10,9);
  cout << "Enter an amount of money, (use the dollar sign in front): "; 
  cin >> yourAmount;
  cout << "Your amount is: " << yourAmount << endl;


  return 0;
}
