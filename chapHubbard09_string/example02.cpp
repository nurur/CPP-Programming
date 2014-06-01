// Example: 9.5
// reading one 'string' at a time from a line 
// consisting of several strings 


#include <cctype>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;



int main()
{ 
  string s;
  char c;
  int k;


  cout << "Enter a line of strings: ";
  while (cin >> s)
    {
      k = s.find("t") + 1;
      if ( k < s.length() && is_vowel(s[k]) )
	  s.replace(k, 0, "xyz");
      
      cout << s << ' ';
    }
  

  cout << endl;
  return 0;
}
