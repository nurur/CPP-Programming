// Problem 7.7, chap 7 (C++, J R Hubbard)
//
// Method 1
// Function takes a pointer to an array and 
// Returns the array elements in reverse order 
//
// Method 2
// Function takes an array of n pointers and 
// Returns the array elements in reverse order 
 

#include <iostream>
using namespace std;


float* mirror1(float* p, int n)
// Return array elements in reverse order 
{ 
  float* r = new float[n];
  int j = 0;
  for (int i=(n-1); i>=0; i--) 
    {   
      r[j] = p[i]; 
      j++;
    }   
  return r;
}


float* mirror2(float* p[], int n)
// Return array elements in reverse order 
{ 
  float* r = new float[n];
  int j = 0;
  for (int i=(n-1); i>=0; i--) 
    {   
      r[j] = *p[i]; 
      j++;
    }   
  return r;
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
  const int SIZE = 5;
  float a[SIZE] = {11.0, 22.0, 33.0, 44.0, 55.0};
  cout << endl;    

  cout << "The original array elements are : " << endl;
  printA(a,SIZE);
  cout << endl;

  // Reverse the array, Method 1
  // Function Input is Pointer to an array
  cout << "Using Method 1 ... ... ... \n";
  cout << "The reverse array elements are : " << endl;
  float* p = a;
  float* q = mirror1(p,SIZE);
  printP(q,SIZE);
  
  delete [] q; q=0;
  cout << endl;


  // Reverse the array, Method 2
  // Function Input is Array of Pointers
  float* pp[SIZE];
  for(int i = 0; i < SIZE; i++)
    pp[i] = &a[i]; 
    
  cout << "Using Method 2 ... ... ... \n";
  cout << "The reverse array elements are : " << endl;
  float* qq = mirror2(pp,SIZE);
  printP(qq,SIZE);
  
  delete [] qq; qq=0;

  return 0;
}





