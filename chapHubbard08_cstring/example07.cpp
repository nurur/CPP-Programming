// EXAMPLE: 8.12 
// array of strings
// typical text: George Washington, John Adams, Thomas Jeferson 

#include <cstdlib>
#include <iostream>
using namespace std;


int main ()
{
  // check
  // Example 8.10
  int i;
  int count = 0;
  char name[3][20];
  cout << "Enter the names:\n";
  cout << "Each name must be at most 19 characters: " << endl;
    
  while( cin.getline(name[count++],20) )
    { cout << ""; }
  --count;

  cout << "count : " << count << endl;

  cout << endl;
  cout << "check 1 :" << endl;
  cout << "The names are: \n";
  for (i = 0; i < count; i++)
    cout << i << " : " << name[i] << endl;
  
  

  // check
  // Example 8.11
  //char buffer[80];
  //cin.getline(buffer,80);
  char buffer[80] = "\nGeorge Washington\nJohn Adams\nThomas Jeferson\n";

  char* nm[4];
  nm[0]   = buffer;        // copy the entire buffer to nm[0]
  char* p = buffer;

  int cnt = 0;
  for (p; *p !='\0'; p++)
    { if (*p == '\n') 
      { *p = '\0';        // end name
	nm[cnt++] = p+1;  // begin next name
      }
    }  
  --cnt;

  cout << endl;
  cout << "check 2 :" << endl;
  cout << "The names are: \n";
  for (i = 0; i < cnt; i++)
    cout << i << " : " << nm[i] << endl;
  



  // check 
  // Example 8.12
  int n   = 3;
  char* names[]= {"George Washington", "John Adams", "Thomas Jeferson"};

  cout << endl;
  cout << "check 3 :" << endl;
  cout << "The names are: \n";
  for (i = 0; i < n; i++)
    cout << i << " : " << names[i] << endl;
  
  return 0;
}

