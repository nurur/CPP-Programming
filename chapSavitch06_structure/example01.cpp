// Example: 6.1
// Structure
// Structure as Function argument 
// Structure type as a type Returned by a Function  


#include <iostream>
using namespace std;



struct CDAccount
{
  double balance;
  double interRate;
  int term;
};


void getData(CDAccount& theAccount)
{
  cout << "Enter the account balance: $";
  cin >> theAccount.balance;

  cout << "Enter the account interest rate: ";
  cin >> theAccount.interRate;

  cout << "Enter the number of months until maturity: ";
  cin >> theAccount.term;
}


CDAccount doubleInerest(CDAccount oldAccount)
{
  CDAccount tmp;
  tmp = oldAccount;
  tmp.interRate = 2. * oldAccount.interRate;

  return tmp;
}




int main()
{
  CDAccount oldAccount;
  getData(oldAccount);

  double rateFraction;
  rateFraction = oldAccount.interRate/100.;

  CDAccount newAccount;
  newAccount = doubleInerest(oldAccount);
  cout << newAccount.interRate << endl;
  

  return 0;
}
