// Problem 9.7
// change all capital letters in string s to lowercase
// typical input: %ThisALongchaiN!


#include <cctype>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;


bool isupperCase(char& c)
{ if ( isupper(c) ) c = tolower(c); }

bool islowerCase(char& c)
{ if ( islower(c) ) c = tolower(c); }

bool isletterCase(char c)
//{ return bool ( isupper(c) || islower(c) ); }
{ return bool ( ispunct(c) || isspace(c) ); }


void reduce(string& s)
{
  cout << "original length : " << s.length() << endl;
  while ( s.length() > 0 && isletterCase( s[0] ) ) // first letter
    s.erase(0,1);
  //cout << "length : " << s.length() << endl;

  int ind = s.length()-1;
  cout << "index : " << ind << endl;
  while ( ind > 0 &&  isletterCase( s[ind--] ) )   // last letter
    s.erase(ind+1,1);
    
  int len = s.length();
  if (len == 0) return;
  cout << "final length    : " << len << endl;

  for (int i = 0; i < len; i++)
    {
      isupperCase( s[i] ); 
      if ( isletterCase(s[i]) )  s.erase(i,1); 
    }  
}




int main()
{ 
  string s;
  char c;
  cout << "Enter a string   : "; cin >> s;
  reduce(s);
  cout << "The new string is: " << s << endl;

  return 0;
}
