// problem 7.3, chap 7 (C++, J R Hubbard)
// write a function that takes an array of n pointers to float 
// and returns a newly created array that contains those n floats 
 

#include <iostream>
using namespace std;


float* duplicate(float* p[], int n)
{
  float* d = new float[n];
  for(int i=0; i<n; i++)
    d[i] = *p[i];
    
  return d;
}


void printA(float a[], int n)
{
  for(int i = 0; i<n; i++)
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
  const int SIZE = 5;
  float a[SIZE] = {11.0,22.0,33.0,44.0,55.0};
  cout << endl;    

  cout << "elements of the array are: " << endl;
  printA(a,SIZE);

  float* p[SIZE];
  for(int i = 0; i < SIZE; i++)
    p[i] = &a[i]; 


  float *b = duplicate(p,SIZE);
  printP(b,SIZE);

  delete [] b; b=0;

  cout << endl;    
  return 0;
}




