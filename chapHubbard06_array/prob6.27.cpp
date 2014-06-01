// Problem: 6.27,  chaper 6 (C++, J Hubbard)
// Inner product of two arrays 



#include <iostream>
using namespace std;


float innerProduct(float a[], float b[], int n)
{
  float sum = 0.;
  for (int i=0; i<n; i++)
    sum += a[i] * b[i];
  
  return sum;
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

  // Inner product of two arrays 
  float scalar = innerProduct(a,b,SIZE);
  cout << "The inner product of two arrays is : " <<  scalar << endl;

  return 0;
}
