// Example: 9.15
// Palindrom: a word which is its reverse
// e.g. : MOM, RADAR, BABY BAB


#include <cctype>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;


void reverse(string& s)
{
  string t;
  int len = s.length();
  for (int i=0; i < len; i++)
    {
      t[i] = s[len-i-1];
      cout << t[i] << endl;
    }

  for (int i=0; i < len; i++)
    { 
      s[i] = t[i];   //assign t to s
    } 
}



bool is_palindrom(string s1, string s2)
{
  if (s1 == s2) 
    { cout << "The string is a Palindrom";
      return true;
    }
  else 
    { cout << "The string is not a Palindrom";
      return false;
    }
}



int main()
{ 
  string os;
  string s1, s2;

  //string s;
  //getline(cin,s);
  //cout << s << " " << s.length() << " " << s.substr() << endl;
  
  // check
  // reversing a string 
  //s = string( s.rbegin(), s.rend() );
  //cout << s << endl;

  // check
  cout << "Enter a string   : "; cin >> os;
  s1 = os;
  reverse(os);
  cout << "The new string is: " << os << endl;

  // check Palindrom 
  s2 = os;
  is_palindrom(s1,s2); 

  cout << endl;
  return 0;
}
