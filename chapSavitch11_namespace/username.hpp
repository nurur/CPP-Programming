// Header File 1: username.hpp
// Namespace 
// Unnamed Namespace


#ifndef USERNAME_HPP
#define USERNAME_HPP 


#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


namespace 
{
  char username[20]  = "";

  bool isValid()
  { 
    int SIZE = strlen(username);  

    if (SIZE >= 8) return true;
    else
      { cout << "Error: username must have at least 8 letters!"<< endl;
	return false;
      }
  }
} // unnamed namespace 



namespace AuthenticateUsername 
{
  void inputUsername()
  {    
    do
      { cout << "Enter your username (8 letters or more)  " << endl;
	cin >> username;
      } while( !isValid() );
  }

  string getUsername()
  {
    return username;
  }
}


#endif  //USERNAME_HPP
