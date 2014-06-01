// Problem 9.2
// String functions: erase(), find(), insert(), length(), 
// replace(), reverse(), substr()


#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;


int main()
{
  string s = "ABCDEFGHIJKLMNOP";
  cout << s << " " << s.length() << endl;

  s[8] = '!';
  cout << s << endl;
  s.replace(8, 5, "xyz");
  cout << s << endl;
  s.erase(6,4);
  cout << s << endl;

  cout << s.find('!')  << endl;;
  cout << s.find('?')  << endl;
  cout << s.substr(6,3)<< endl;

  s += "abcde";
  cout << s << endl;
  string part(s,4,8);
  cout << part << endl;
  string star(8,'*');
  cout << star << endl;


  cout << endl;
  return 0;
}
