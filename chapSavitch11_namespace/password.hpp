// Header File 2: password.hpp
// Namespace 
// Unnamed Namespace


#ifndef PASSWORD_HPP
#define PASSWORD_HPP


#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


namespace 
{
  char password[20] = "";
  
  bool isValid()
  {
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
      { cout << "Error: password must be at least 8 characters long!"<<endl;
	return false;
      } 
  } 
} // unnamed namespace 



namespace AuthenticatePassword 
{
  void inputPassword()
  {  
    do
      { cout << "Enter your password (at least 8 characters " 
	     << "and at least one non-letter)" << endl;
	cin >> password;
      } while( !isValid() );
  }
  
  string getPassword()
  {
    return password;
  }
}


#endif  //PASSWORD_HPP
