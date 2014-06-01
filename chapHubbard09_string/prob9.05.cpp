// Problem 9.3
// 
// typical input: Johaan Sebastian Bach

#include <cstring>
#include <string>
#include <iostream>
using namespace std;


int main()
{ 
  string first, middle, last;
  string s; 
  char c;

  bool isFirst, isLast;
  isLast = true;
  string name[40];      //an array of string
  int n = 0;

  cout << "Enter the name: first, middle, last: ";
  while (cin >> s)
    { 
      cin.get(c);                // should be either a blank or a newline
      isFirst= isLast;           // current word is first name
      isLast = bool(c == '\n');  // current word is a last name
      
      if (isFirst) first = s;
      else if (isLast) name[n++] = s + ", " + first;
      else first = first + " " + s.substr(0,1) + ".";
    }
  
  for (int i = 0; i < n; i++)
    cout << i+1 << ". " << name[i] << endl; 
 

  return 0;
}
