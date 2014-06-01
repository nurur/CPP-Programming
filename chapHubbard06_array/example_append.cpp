// Problem 6.16, chaper 6 (C++, J Hubbard)
// Appends first n elements of an array onto 
// the end of the first m elements of another  


#include <cstdlib>
#include <iostream>
using namespace std;


void appendArray(float a[], int m, float b[], int n)
{
  int j = 0;
  for (int i=m; i<(m+n); i++)
    {
      a[i] = b[j];
      ++j;
    }
}


void printA(float a[], int n)
{
  for(int i=0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}



int main()
{
   const int SIZE = 9;
   float a[SIZE] = {55.5, 22.5, 99.9, 11.1, 66.6};
   float b[SIZE] = {44.4, 88.8, 33.3, 77.7};
    
  cout << "The array elements are: " << endl;
  printA(a,SIZE);
  printA(b,SIZE);

  cout << "Appending b onto a ... ... " << endl;
  int m = 5;
  int n = 4;
  appendArray(a,m,b,n);
  printA(a,SIZE);

  return 0;
}
