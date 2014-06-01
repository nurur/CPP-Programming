// Example: Review questions 8.7 & 8.14

 
#include <cstring>
#include <string>
#include <iostream>
using namespace std;




int main()
{
  // check
  char s[] = "123 W. 42nd St., NY, NY 10020-1095";
  char* p  = s;
  for (p; *p; p++)
    if ( ispunct(*p) ) *(p-1) = tolower(*p);
  cout << s << endl;


  //check
  char* s1 = " ";
  char* s2 = "";
  if (strcmp(s1,s2) == 0) cout << s1 << " == " << s2 << endl;
  else cout << s1 << " != " << s2 << endl;


  return 0;
}
