// Problem: 6.28,  chaper 6 (C++, J Hubbard)
// Outer product of two arrays 



#include <iostream>
using namespace std;


float outerProduct(float a[], float b[], float c[][3])
{
  for (int i=0; i<3; i++) 	
    for (int j=0; j<3; j++) 	
      c[i][j] = a[i] * b[j];
}


void printA(float a[], int n)
{
  for(int i = 0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}




int main()
{
  const int SIZE = 3;
  float a[SIZE] = {1.1, 2.2, 3.1};
  float b[SIZE] = {1.5, 1.8, 2.4};

  cout << "The array elements are ...  " << endl;
  printA(a,SIZE);
  printA(b,SIZE);
  cout << endl;  

  // Outer product of two arrays 
  float c[SIZE][SIZE];
  outerProduct(a,b,c);

  cout << "The outer product of two arrays is : " << endl;
  for(int i=0; i<SIZE; i++)
    { 
      for(int j=0; j<SIZE; j++)
	cout << c[i][j] << " ";  
      cout << endl;  
    }

  return 0;
}
