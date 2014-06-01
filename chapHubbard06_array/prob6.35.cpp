// Problem: 6.35,  chaper 6 (C++, J Hubbard)
// Pascal's triangle 


#include <cassert>
#include <iostream>
using namespace std;


void buildPascal(int a[][5], int n)
{  
  // Check the array 
  assert(n > 0);
  
  // Build the triangle 
    for (int i=0; i<n; i++)
      for (int j=0; j<n; j++)
	if (j > i) a[i][j] = 0;
	else if (j == 0 || i==j)  a[i][j] = 1;
	else a[i][j] = a[i-1][j-1] + a[i-1][j];
}




int main()
{
  const int SIZE = 5;
  int a[SIZE][SIZE];
  
  // Intialize Pascal's triangle
  for (int i=0; i<SIZE; i++)
    for (int j=0; j<SIZE; j++)
      a[i][j] = 0;

  
  // Invoke Pascal's triangle
  buildPascal(a, SIZE);
  // Print Pascal's triangle
  for (int i=0; i<SIZE; i++)
    {
      for (int j=0; j<SIZE; j++)	
	cout << a[i][j] << " ";
      cout << endl;
    }



  return 0; 
}
