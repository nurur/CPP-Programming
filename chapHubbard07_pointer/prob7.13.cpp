// Problem 7.13, chaper 7 (C++, J R Hubbard)


#include <iostream>
using namespace std;


float sum(float* p[], int n)
{
  float x = 0.;
  for (int i=0; i<n; i++) 
    x += *p[i]; 
  
  return x;
}

void printA(float a[], int n)
{
  for(int i=0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}

void printP(float* a, int n)
{
  for(int i=0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}




int main ()
{
  const int SIZE = 6;
  float a[SIZE] = {11.0, 22.0, 33.0, 44.0, 55.0, 19.0};
  cout << endl;    

  cout << "The original array elements are : " << endl;
  printA(a,SIZE);
  cout << endl;

  float* p[SIZE];
  for(int i = 0; i < SIZE; i++)
    p[i] = &a[i]; 
    
  float x =sum(p,SIZE);
  cout << "The sum of the array elements is : " << x << endl;
 

  return 0;
}

