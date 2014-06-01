// Main Programm
// Namespace 
// Unnamed Namespace


#include "username.hpp"
#include "password.hpp"
#include <cstdlib>
#include <cstring>  
#include <iostream>
using namespace std;



int main()
{
  AuthenticateUsername :: inputUsername();
  AuthenticatePassword :: inputPassword();
 
  cout << "username is " << AuthenticateUsername::getUsername() << " and "
       << "password is " << AuthenticatePassword::getPassword() << endl;
  
  cout << endl;
  return 0;
}
