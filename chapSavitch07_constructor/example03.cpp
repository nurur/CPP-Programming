// Example: 7.4
// Class with Constructors
// Using 'const' modifier to member functions of Example 7.2


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
  void output() const;   

  int getDollars() const;
  int getCents() const;
  double getBalance() const;
  double getRate() const;

  void setBalance(double balance);
  void setBalance(int dollars, int cents);
  void setRate(double newrate);


private:
  int accountDollars;
  int accountCents;
  double rate;

  int dollarsPart(double amount)  const;
  int   centsPart(double amount)  const;
  int       round(double number)  const;
  double fraction(double percent) const;
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


void bankAccount :: output() const
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

int bankAccount :: getDollars() const
{ return accountDollars; }

int bankAccount :: getCents() const
{ return accountCents; }

double bankAccount :: getBalance() const
{ return accountDollars + accountCents * 100; }

double bankAccount :: getRate() const 
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
int bankAccount :: dollarsPart(double amount) const
{
  return static_cast<int> (amount);              //Use <cmath>
}

int bankAccount :: centsPart(double amount) const
{
  double doubleCents = amount * 100;
  int intCents       =  (round(fabs(doubleCents)) );
  if (amount < 0)  intCents = -intCents;

  return (intCents % 100);                      //Return the amount in 'cents' 
}

int bankAccount :: round(double number) const
{
  return static_cast<int> (floor (number+0.5)); //Use <cmath>
}

double bankAccount :: fraction(double percent) const
{
  return (percent/100.0);
}



//Newly added
bool isLarger(const bankAccount& account1, const bankAccount& account2) 
{
  return ( account1.getBalance() > account2.getBalance() );
}


//Newly added
void welcome(const bankAccount& yourAccount) 
{
  cout << "Welcome to our bank.\n"
       << "The status of your account is:\n";

  yourAccount.output();
}




int main()
{
  bankAccount account1(1345.52, 2.3), account2;
  welcome(account1);
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
