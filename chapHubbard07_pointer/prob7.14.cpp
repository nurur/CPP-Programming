// Problem 7.14, chaper 7 (C++, J R Hubbard)


#include <cmath>
#include <iostream>
using namespace std;


void abs(float* p[], int n)
{
  for (int i=0; i<n; i++) 
    *p[i]= abs( *p[i]) ; 
}

void printA(float a[], int n)
{
  for(int i=0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}

void printP(float* a[], int n)
{
  for(int i=0; i<n; i++)
    cout << *a[i] << " ";  
  cout << endl;  
}




int main ()
{
  const int SIZE = 6;
  float a[SIZE] = {-11.0, -22.0, -33.0, -44.0, -55.0, -19.0};
  cout << endl;    

  cout << "The original array elements are : " << endl;
  printA(a,SIZE);
  cout << endl;

  float* p[SIZE];
  for(int i = 0; i < SIZE; i++)
    p[i] = &a[i]; 
     
  cout << "The new array elements are : " << endl;
  abs(p, SIZE);
  printP(p,SIZE);
  
  return 0;
}

