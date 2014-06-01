// Example: 9.14
// reading one 'string' at a time from a line 
// consisting of several strings 


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



int main()
{ 
  string s;
  char c;
  int k;

  //string s;
  //getline(cin,s);
  //cout << s << " " << s.length() << " " << s.substr() << endl;
  
  // check
  // reversing a string 
  //s = string( s.rbegin(), s.rend() );
  //cout << s << endl;

  // check
  cout << "Enter a string   : "; cin >> s;
  reverse(s);
  cout << "The new string is: " << s << endl;
  
  return 0;
}
