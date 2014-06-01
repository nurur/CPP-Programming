// EXAMPLE: 8.1, 8.2


#include <iostream>
using namespace std;



int main ()
{
  // check 
  const int n = 5;
  char c[]    = "ABCD";
  
  for (int i = 0; i < n; i++)
    cout << "c[" << i << "] = ' " << c[i] << " ' " << endl;
  cout << endl;
  

  char s[] = "Hello there";
  cout << s << endl;
  cout << endl;
  
  
  // check 
  cout << "printing single, double quotes:" << "\'" 
       << ", " << "\"" << endl;
  cout << "printing back slash           :" << "\\" 
       << endl;
  cout << "printing forward slash        :" << "/" 
       << endl;
  

  cout << endl;
  return 0;
}
