// Example: 7.2
// Class with Constructors


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;



class bankAccount
{
public:
  bankAccount();
  //initialize account balance to 0.00 and rate to 0.00%
 
  bankAccount(double balance, double rate);
  //initialize balance and rate according to arguments

  bankAccount(int dollars, double rate);
  //initialize account balance to $dollars.0.00 and 
  //initilize the interest rate to rate percent

  bankAccount(int dollars, int cents, double rate);
  //initialize account balance to $dollars.cents and 
  //initilize the interest rate to rate percent

  void update();
  void  input();   
  void output();   

  int getDollars();
  int getCents();
  double getBalance();
  double getRate();

  void setBalance(double balance);
  void setBalance(int dollars, int cents);
  void setRate(double newrate);


private:
  int accountDollars;
  int accountCents;
  double rate;

  int dollarsPart(double amount);
  int   centsPart(double amount);
  int       round(double number);
  double fraction(double percent);
};



// constructors 
bankAccount :: bankAccount()
{
  accountDollars = 0.0;
  accountCents   = 0.0;
  rate    = 0.0;
}
 
bankAccount :: bankAccount(double balance, double rate)
{
  accountDollars = dollarsPart(balance);
  accountCents   = centsPart(balance);

  setRate(rate);
}
 
bankAccount :: bankAccount(int dollars, double rate)
{
  setBalance(dollars, 0.0);
  setRate(rate);
}


bankAccount :: bankAccount(int dollars, int cents, double rate)
{
  setBalance(dollars, cents);
  setRate(rate);
}
 


// public member functions
void bankAccount :: update()
{
  double balance = accountDollars + accountCents * 0.01;
  balance  = balance + fraction(rate) * balance;

  accountDollars = dollarsPart(balance);
  accountCents   = centsPart(balance);
}

void bankAccount :: input()
{
  double balanceAsDouble;
  cout << "Enter account balance in $: "; 
  cin >> balanceAsDouble;

  accountDollars = dollarsPart(balanceAsDouble);
  accountCents   = centsPart(balanceAsDouble);
  
  cout << "Enter interest rate (No percent sign): ";
  cin >> rate;
  setRate(rate);
}


void bankAccount :: output()
{
  int absDollars = abs(accountDollars);
  int absCents   = abs(accountCents);
  cout << "Account balance: $";

  if (accountDollars < 0) cout << "$-";
  cout << accountDollars;

  if (absCents >= 10)
    cout << "." << absCents << endl;
  else
    cout << "." << '0' << absCents << endl;
  
  cout << "Rate: " << rate << "%" << endl;; 
}

int bankAccount :: getDollars()
{ return accountDollars; }

int bankAccount :: getCents()
{ return accountCents; }

double bankAccount :: getBalance()
{ return accountDollars + accountCents * 100; }

double bankAccount :: getRate()
{ return rate; }


void bankAccount :: setBalance(double balance)
{
  accountDollars = dollarsPart(balance);
  accountCents   = centsPart(balance);
}

void bankAccount :: setBalance(int dollars, int cents)
{
  if ( (dollars < 0 && cents > 0) || (dollars > 0 && cents < 0) )
    {
      cout << "Inconsistent account data.\n";
      exit(1);
    }
  accountDollars = dollars;
  accountCents   = cents;
}

void bankAccount :: setRate(double newrate)
{
  if (newrate > 0.0) rate = newrate;
  else 
    { 
      cout << "Cannot have negative interest rate.\n";
      exit(1);
    }
}



// private member functions 
int bankAccount :: dollarsPart(double amount)
{
  return static_cast<int> (amount);              //Use <cmath>
}

int bankAccount :: centsPart(double amount)
{
  double doubleCents = amount * 100;
  int intCents       =  (round(fabs(doubleCents)) );
  if (amount < 0)  intCents = -intCents;

  return (intCents % 100);                      //Return the amount in 'cents' 
}

int bankAccount :: round(double number)
{
  return static_cast<int> (floor (number+0.5)); //Use <cmath>
}

double bankAccount :: fraction(double percent)
{
  return (percent/100.0);
}






int main()
{
  bankAccount account1(1345.52, 2.3), account2;
  cout << "Account 1 :\n"; 
  account1.output();
  cout << endl;

  cout << "Account 2 :\n";
  account2.output();
  cout << endl;

  
  account1 = bankAccount(999, 99, 5.5);
  cout << "Account 1 reset to the following :\n";
  account1.output();
  

  cout << "Enter new data for account 2 :\n";
  account2.input();
  cout << "Account 2 reset to the following :\n";
  account2.output();

  return 0;
}
