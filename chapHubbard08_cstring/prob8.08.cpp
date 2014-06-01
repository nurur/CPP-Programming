// PROBLEM: 8.08
// strchr()
// First occurence of a character in a C-string 


#include <cstring>
#include <string>
#include <iostream>
using namespace std;


char* stringChar(const char* s, int c)
{ 
  const char* p = s;

  // search 'c' within 's'
  // return a 'pointer to c', if 'c' is within 's'
  for (p; p && *p; p++)    
    { if (*p == c) 
	{ 
	  return (char*)p; 
	}
    }

// return null, if 'c' is not within 's'
//  return 0;  
}



int main ()
{

  char* s = "Hello World!, This is Nurur Rahman.";
  char  c = 'l';
  char* p = stringChar(s,c);

  cout << "First occurence of character, " << c 
       << ", in C-string: " << s << endl; 
  cout << &p << "--" << *p << "--" << p-s << endl;


  // check strchr() & stringChar()
  char  d = 'k';
  char* q = strchr(s,d);
  cout << &q << "--" << *q << "--" << q-s << endl;


  return 0;
}
