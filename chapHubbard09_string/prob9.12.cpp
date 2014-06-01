// Problem 9.12, 9.13
// convert decimal numerals to hexadecimal


#include <cassert>
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;


// decimal - hexadecimal
char c (int k)
{
  assert(k > 0 && k <= 15 );
  if (k < 10) return char(k + '0');
  return char(k - 10 + 'a');
} 


string hexadecimal(int n)
{
  string s;
  int k;

  if (n < 0) 
    { cout << "Error: Input must be a positive interger!" << endl; 
      exit(1);
    }

  if (n == 0) return string(1,'0');

  while (n > 0)
    {
      //cout << n << " " << (n/16) << " " << c(n%16) << " " << s << endl;
      k = n%16;     // reminder which must be less than 16, i.e., 0 - 15
      s  = string( 1, c(k) ) + s;
      n /= 16;
    }
  return s;
}





//hexadecimal - decimal
int v(string s, int i)  
{
  char c = s[i];
  assert(c >= '0' && c <= '9' || c >= 'a' && c <= 'f');
  if (c >= '0' && c <= '9') return int(c - '0');
  else return int(c + 10 - 'a');
}


int decimal(string s)
{
  int len = s.length();
  assert(len > 0);

  int n = 0;
  for (int i=0; i < len; i++)
    n = 16*n + v(s,i);

  return n;
}




int main()
{
  string s;
  int n;

  // decimal - hexadecimal
  cout << "Enter a decimal number        : "; cin >> n;
  cout << "Equivalent hexadecimal number : " <<  hexadecimal(n) << endl;



  return 0;
}
