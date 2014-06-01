// Example : 10.9
// Two-dimensional Array 
// Dynamic memory allocation 
// Note:
// Pointer to Pointer


#include <iostream>
using namespace std;


int main()
{
  int nrows, ncols;
  nrows = 3;
  ncols = 4;

  // method 1
  cout << "Primitive way to declare an array of pointers:" << endl;

  int **arrayTwoD = 0;
  // allocate memory for the rows
  arrayTwoD = new int*[nrows];

  // for each row, allocate memory for the columns 
  for (int i=0; i < nrows; i++)    
    arrayTwoD[i] = new int[ncols];

  // provide input 
  for (int i=0; i < nrows; i++)    
    for (int j=0; j < ncols; j++)    
      cin >> arrayTwoD[i][j];
  cout << endl;
  
  // print output 
  for (int i=0; i < nrows; i++)    
    { 
      for (int j=0; j < ncols; j++)    
	cout << arrayTwoD[i][j] << " ";
      cout << endl;
    }

  // free memeory allocations 
  for (int i=0; i < nrows; i++)    
    delete[] arrayTwoD[i];
  delete[] arrayTwoD;  
  cout << endl;



  // method 2
  int d1, d2;
  d1 = 3;
  d2 = 4;
  cout << "Alternative way to declare an array of pointers:" << endl;

  typedef int* intPtr;
  intPtr *n = new intPtr[d1];

  // get rows
  for (int i=0; i<d1; i++)    
    n[i] = new int[d2];

  // for each row, get columns 
  for (int i=0; i<d1; i++)    
    for (int j=0; j<d2; j++)    
      cin >> n[i][j];
  cout << endl;
  
  // print 
  for (int i=0; i<d1; i++)    
    { 
      for (int j=0; j<d2; j++)    
	cout << n[i][j] << " ";
      cout << endl;
    }

  // free memeory allocations 
  for (int i=0; i<d1; i++)    
    delete[] n[i];
  
  delete[] n;  
  

  int  *a = new int[4];
  int **b = &a;
  
  cout << **b << endl;
  cout << endl;  
  return 0;
}
