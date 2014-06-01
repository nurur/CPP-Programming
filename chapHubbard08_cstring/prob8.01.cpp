// PROBLEM: 8.01 
// array of strings
// typical text: George Washington, John Adams, Thomas Jeferson 


#include <cstring>
#include <iostream>
using namespace std;


int main ()
{
  char name[3][20], buffer[20];
  int count = 0; 
  cout << "Enter the names:\n";
  cout << "Each name must be at most 19 characters: " << endl;

  while( cin.getline(buffer,20) )
    {
      // name[count++] = buffer;  // Error! 
      // count++;                 // arrays can not be assigned this way 

      strcpy(name[count++], buffer); 
    }  

  cout << "The names are: \n";
  for (int i = 0; i < count; i++)
    cout << i << " : " << name[i] << endl;
  

  return 0;
}

