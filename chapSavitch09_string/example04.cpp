// Example: 
// Self-Test exercise 9.24, 9.25
// understanding strcmp() function 


#include <cctype>
#include <cstring>
#include <string>
#include <iostream>
using namespace std;



int main()
{
  // check 
  string s1, s2("Good");
  cout << "Enter a line of input: "; cin >> s1;

  if (s1 == s2) cout << "Equal\n";
  else cout << "Not equal\n";
  cout << endl; 



  // check
  string s3, s4("Merry");
  s3 = s4;
  s4[0] = 'J';
  if (s3 == s4) cout << "Equal\n";
  else cout << "Not equal\n";
  cout << endl;



  // check 
  char s5[6]; 
  char s6[6] = "Merry";

  strcpy(s5,s6);
  s5[0] = 'J';
  cout << s5 << " & " << s6 << endl;

  if ( strcmp(s5,s6) <  0) 
    cout << "negative, " << s5 << " < " << s6 << endl;
  if ( strcmp(s5,s6) == 0) 
    cout << "equal,    " << s5 << " = " << s6 << endl;
  if ( strcmp(s5,s6) >  0) 
    cout << "positive, " << s5 << " > " << s6 << endl;


  // check
  char* s10  = "Hukkah";
  char* p = s10;
  int n = strlen(s10);


  cout << endl;
  return 0;
}
