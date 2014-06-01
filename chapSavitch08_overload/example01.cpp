// Example: 8.1
// Class Money 
//
// Overloading operators as non-member functions
// Overloading operators outside the Class interface 


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


class Money
// Class for amounts of money in US currency
{
public:
  Money();
  Money(double amount);
  Money(int theDollars);
  Money(int theDollars, int theCents);

  // member functions
  void  input();   
  void output();   
  double getAmount() const;
  int   getDollars() const;
  int     getCents() const;

private:
  int dollars;
  int cents;

  int dollarsPart(double amount) const; 
  int   centsPart(double amount) const;
  int       round(double number) const;
};


// Overloaded operators outside Class interface (non-class, non-member) 
// binary (+ and -) operator
// unary (negation, -) operator
const Money operator+(const Money& amount1, const Money& amount2);
const Money operator-(const Money& amount1, const Money& amount2);
bool operator==(const Money& amount1, const Money& amount2);
const Money operator-(const Money& amount); 


int main()
{
  Money yourAmount, myAmount(10,9);
  cout << "Enter an amount of money, (use the dollar sign in front): "; 
  yourAmount.input();
  cout << "Your amount is: "; 
  yourAmount.output();
  cout << endl;

  cout << "My amount is  : "; 
  myAmount.output();
  cout << endl;

  return 0;
}




const Money operator+(const Money& amount1, const Money& amount2) 
{
  int allCents1   = amount1.getCents() + amount1.getDollars() * 100;
  int allCents2   = amount2.getCents() + amount2.getDollars() * 100; 
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
  int allCents1   = amount1.getCents() + amount1.getDollars() * 100;
  int allCents2   = amount2.getCents() + amount2.getDollars() * 100; 
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

//Unary negation 
const Money operator-(const Money& amount)
{
  return Money(-amount.getDollars(), -amount.getCents());
}

//Equal to 
bool operator==(const Money& amount1, const Money& amount2)
{
  return ( (amount1.getDollars() == amount2.getDollars())
	   && (amount1.getCents()== amount2.getCents()) );
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
void  Money :: input() 
{
  char dollarSign;
  cin >> dollarSign;

  if (dollarSign != '$') // if (strcmp(dollarSign, '$') == 0)
    {
      cout << "No dollar sign in Money input. \n";
      exit(1);
    }

  double amountAsDouble;
  cin >>  amountAsDouble;

  dollars = dollarsPart(amountAsDouble);
  cents   = centsPart(amountAsDouble);
}   

void Money :: output() 
{
  int absDollars = abs(dollars);
  int absCents   = abs(cents);
  cout << "Account balance: ";
  
  if (dollars < 0 || cents < 0) 
    cout << "$";
  else 
    cout << '$';
  cout << dollars;
  
  if (absCents >= 10)
    cout << "." << absCents << endl;
  else
    cout << "." << '0' << absCents << endl;
} 

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

  return (intCents % 100);  //Return the amount in 'cents' 
}

int Money :: round(double number) const 
{
  return static_cast<int> (floor (number+0.5)); //Use <cmath>
}


