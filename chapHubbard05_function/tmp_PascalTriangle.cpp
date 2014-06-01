// Problem 5.16, chap 5 (C++, J R Hubbard)
// Pascal's Triangle using Combination Function  


#include <iomanip>
#include <iostream>
using namespace std;


long combFunc1(int n, int k)
// Using for loop
{
  long var;
  if (n < 0 || k < 0 || k > n) return 0;
  
  int f = 1;
  for (int i=1; i<=k; i++)
    { 
      f *= n--;
      f /= i;
    }
  return f;
}


long combFunc2(int n, int k)
// Using while loop
{
  long var;
  if (n < 0 || k < 0 || k > n) return 0;
  
  int f = 1;
  int i = 1;
  while (k >= 1) 
    { 
      f *= n--;
      f /= i++;
      k--;
    }
  return f;
}



int main()
{
  int const m = 9;

  for (int i=0; i<m; i++)
    {
      for (int k=1; k<m-i; k++)
	cout << setw(2) << "";
      for (int j=0; j<=i; j++)
	cout << setw(4) << combFunc1(i,j);
      cout << endl;
    }

  return 0;
}
