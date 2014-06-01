// Problem 7.12, chap 7 (C++, J R Hubbard)


#include <iostream>
using namespace std;


char* charCmp(char* s, char c)
{
  char* p = s;
  for (p; *p !='\0'; p++)
    if (*p == c) return p;
  return 0;
}

void locate(char* s, char c)
{
  char* p = charCmp(s,c);	    
  
  if (p =='\0') cout << "No match found."<< endl; 
  else  
    {
      cout << "Match found.\n";
      cout << "The first occurance of the character '" << c 
	   << "' in the string is at the positon: " << p-s 
	   << endl;
    }
}



int main ()
{
  locate("Compare", 'o');
  locate("Compare", 'p');
  locate("Compare", 'n');
 
  return 0;
}
