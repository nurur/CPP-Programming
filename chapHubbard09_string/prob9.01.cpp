// Problem 9.1
// C-String 

#include <cctype>
#include <cstdlib>
#include <cstring>  // needed for c-string 
#include <iostream>
using namespace std;


int main()
{
  char cs1[] = "ABCDEFGHIJ";
  char cs2[] = "ABCDEFGH";
  cout << cs2 << " " << strlen(cs2) << endl;

  cs2[0] = 'X';
  if (strcmp(cs1,cs2) < 0) cout << cs1 << " < " << cs2 << endl;
  else cout << cs1 << " >= " << cs2 << endl;

  char buffer[80];
  strcpy(buffer, cs1);
  cout << "buffer: " << buffer << endl;
  strcat(buffer, cs2);
  cout << "buffer: " << buffer << endl;

  char* cs3 = strchr(buffer, 'G'); // strchr(): first occurance of G in buffer
  cout << cs3 << endl;
  cout << endl;

  // check 
  cout << "printing single, double quotes: " << "\'" << ", " << "\"" << endl;
  cout << "printing back slash           : " << "\\" << endl;
  cout << "printing forward slash        : " << "/" << endl;



  char password[80] = "nurur 12rahman";
  int SIZE = strlen(password);
  int alpha, digit, punct;
  alpha = digit = punct = 0;

  if (SIZE >= 8) 
    { for (int i = 0; i < SIZE; i++)
	{ if ( isalpha(password[i]) ) alpha++;
	  if ( isdigit(password[i]) ) digit++; 
	  if ( ispunct(password[i]) ) punct++;
	}
      if ( digit >= 1 || punct >= 1 ) return true;
      else 
	{ cout << "Error: password must have at least one digit!" << endl;
	  return false;
	}
    }
  else 
    { cout << "Error: password must be at least 8 characters long!" << endl;
	return false;
    } 
  cout << endl;



  cout << endl;
  return 0;
}
