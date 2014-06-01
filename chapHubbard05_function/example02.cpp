// EXAMPLE: 5.10
// Local Variable & Functions 
// Permutation Function 


#include <iostream>
using namespace std;


long factFunc(int n)
{  
  if (n<0) return 0;

  int f = 1;
  while (n>1) 
    { f *= n--; }
  return f;
}


long permFunc(int n, int k)
{
  if (n < 0 || k < 0 || k > n) return 0;
  return factFunc(n)/factFunc(n-k);
}



int main()
{
  for (int i=-1; i<8; i++)
    {
      for (int j=-1; j<=i+1; j++)
	cout << " " << permFunc(i,j);
      cout << endl;
    }

  return 0;
}
