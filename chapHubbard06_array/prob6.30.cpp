// Problem: 6.30,  chaper 6 (C++, J Hubbard)
// Clockwise rotation of the rows a 2D array 



#include <iostream>
using namespace std;



float rotateRows(int a[][3], int nr, int nc)
{
  int m, n;
  float b[nr][nc];
  
  n = 2;
  for (int i=0; i<3; i++) 	
    {
      m = 0;
      for (int j=0; j<3; j++) 	
	{
	  b[m][n] = a[i][j];
	  ++m;
	}
      --n;
    }  
  // Pass rotated arry b to original array a
  for(int i=0; i<nr; i++)
    for(int j=0; j<nc; j++)
      a[i][j] = b[i][j]; 
}



int main()
{
  const int SIZE = 3;
  int a[SIZE][SIZE] = { {11,22,33}, 
			{44,55,66},
			{77,88,99}
                      };
  
  cout << "The array elements are ...  ... ... ... " << endl;
  for(int i=0; i<SIZE; i++)
    { 
      for(int j=0; j<SIZE; j++)
	cout << a[i][j] << " ";  
      cout << endl;  
    }


  // Rotate rows of the array 
  rotateRows(a,SIZE,SIZE);


  cout << "The rotated elements of the arrays are : " << endl;
  for(int i=0; i<SIZE; i++)
    { 
      for(int j=0; j<SIZE; j++)
	cout << a[i][j] << " ";  
      cout << endl;  
    }

  return 0;
}
