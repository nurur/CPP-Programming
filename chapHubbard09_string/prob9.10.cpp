// Problem 9.10
// input Hindu-Arabic numeral
// return Roman numeral read a file 


#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;



string Roman(int n)
{
  int d3 = n/1000;                // thousands digit  
  string s(d3, 'M');
  n %= 1000;


  int d2 = n/100;                // hundreds digit  
  if (d2 == 9) 
    { s += "CM"; }
  else if (d2 >= 5)
    { s += "D";
      s += string(d2-5, 'C');
    } 
  else if (d2 == 4) s += "CD";  
  else s += string(d2,'C');
  n %= 100;


  int d1 = n/10;                  // tens digit
  if (d1 == 9) s += "XC";
    else if (d1 >= 5)
    { s += "L";
      s += string(d1-5, 'X');
    } 
  else if (d1 == 4) s += "XL";  
  else s += string(d1,'X');
  n %= 10;


  int d0 = n/1;
  if (d0 == 9) s += "IX";
    else if (d0 >= 5)
    { s += "V";
      s += string(d0-5, 'I');
    } 
  else if (d0 == 4) s += "IV";  
  else s += string(d0,'I');

  return s;
}





int main()
{
  string s;
  int n;

  cout << "Enter a Hindu-Arabic integer number: "; cin >> n;
  cout << "Equivalent Roman integer number is : " << Roman(n);

  cout << endl;
  return 0;
}
