// Problem 5.12, chap 5 (C++, J R Hubbard)
// Combination Function (Alternative to Problem 5.13, 5.14)


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
  //cout << n << "  " << f << ",  " << f << endl;
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
  // combFunc1 use foor loop;
  cout << "CombFunc1 use foor loop ...  " << endl;
  for (int i=-1; i<8; i++)
    {
      for (int j=-1; j<=i+1; j++)
	//combFunc1(i,j);
	cout << " " << combFunc1(i,j);
      cout << endl;
    }
  cout << endl;


  // combFunc1 use while loop;
  cout << "CombFunc2 use while loop ... " << endl;
  for (int i=-1; i<8; i++)
    {
      for (int j=-1; j<=i+1; j++)
	cout << " " << combFunc2(i,j);
      cout << endl;
    }

  return 0;
}
