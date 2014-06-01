// Problem: 6.36,  chaper 6 (C++, J Hubbard)
// Payoff Matrix of John von Neumann


#include <cassert>
#include <iostream>
using namespace std;


// MiniMax ------------------------------
double max_of_col(int a[][5], int nr, int j)
{
  double max = a[0][j];
  for (int i=1; i<nr; i++)
    if(a[i][j] > max) max = a[i][j];
  
  return max;
}

double minimax(int a[][5], int nr, int nc)   
{
  double minimax = max_of_col(a,nr,0);
  for (int j=1; j<nc; j++)
    {
      double mm = max_of_col(a,nr,j);
      if(mm < minimax) minimax = mm;
    }  
  
  return minimax;
}


// MaxiMin -----------------------------
double min_of_row(int a[][5], int nc, int i)
{
  double min = a[i][0];
  for (int j=1; j<nc; j++)
    if(a[i][j] < min) min = a[i][j];
 
  return min;
}

double maximin(int a[][5], int nr, int nc)  
{
  double maximin = min_of_row(a,nc,0);
  for (int i=1; i<nr; i++)
    {
      double mm = min_of_row(a,nc,i);
      if(mm > maximin) maximin = mm;
    }  

  return maximin;
}




int main()
{
  const int nRows = 3;
  const int nCols = 5;
  int a[nRows][nCols] = { {1,2,3,9,8},
			  {6,7,8,1,2},
			  {3,5,7,8,5} 
                        };

  double x = minimax(a,nRows, nCols);
  double y = maximin(a,nRows, nCols);
  cout << "Minimum of column maximum : " << x << endl;
  cout << "Maximum of row minimum    : " << y << endl;

  return 0;
}
