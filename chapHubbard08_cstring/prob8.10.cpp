// PROBLEM: 8.10
// strrchr()
// Last occurence of a character in a C-string 


#include <cstring>
#include <string>
#include <iostream>
using namespace std;


char* stringRChar(const char* s, int c)
{ 
  const char* p = s;
  const char* pp= 0;   // null pointer

  // search 'c' within 's'
  // return a 'pointer to c', if 'c' is within 's'
  for (p; p && *p; p++)    
    { if (*p == c) 
	{ 
	  pp = p;
	}
    }

  return (char*)pp; 

// return null, if 'c' is not within 's'
//  return 0;  
}



int main ()
{
  char* s = "Hello World!, This is Nurur Rahman.";
  char  c = 'l';
  char* p = stringRChar(s,c);

  cout << "Last occurence of character, " << c 
       << ", in C-string: " << s << endl; 
  cout << &p << "--" << *p << "--" << p-s << endl;


  // check strrchr() & stringRChar()
  char  d = 'k';
  char* q = strchr(s,d);
  cout << &q << "--" << *q << "--" << q-s << endl;


  return 0;
}
