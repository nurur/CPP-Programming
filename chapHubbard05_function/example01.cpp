// EXAMPLE: 5.9 
// Local Variable & Functions 
// Factorial Function 


#include <iostream>
using namespace std;


long factFunc(int n)
{  
  if (n<0) return 0;

  int f = 1;
  while (n>0) 
    {
      f *= n--;
    }
  return f;
}


int main()
{
  for (int i=-1; i<6; i++)
    cout << factFunc(i) << " ";
  
  cout << endl;
  return 0;
}
