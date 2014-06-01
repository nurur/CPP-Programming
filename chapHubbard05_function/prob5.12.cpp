// Problem 5.12, chap 5 (C++, J R Hubbard)
// Permutation Function (Alternative to Example 5.10)


#include <iostream>
using namespace std;


long permFunc1(int n, int k)
// Using for loop
{
  long var;
  if (n < 0 || k < 0 || k > n) return 0;
  
  int f = 1;
  for (int i=1; i<=k; i++)
    f *= n--;

  return f;
}


long permFunc2(int n, int k)
// Using while loop
{
  long var;
  if (n < 0 || k < 0 || k > n) return 0;
  
  int f = 1;
  while (k >= 1) 
    { 
      f *= n--; 
      k--;
    }
  return f;
}



int main()
{
  for (int i=-1; i<6; i++)
    {
      for (int j=-1; j<=i+1; j++)
	cout << " " << permFunc1(i,j);
      cout << endl;
    }

  return 0;
}
