// problem 7.6, chap 7 (C++, J R Hubbard)
// write a function that takes an array of n pointers to float 
// and returns a pointer to the maximum of those n floats 
 

#include <iostream>
using namespace std;


float* getMax(float* p[], int n)
{
  float* maxVal = p[0];    
  
  for (int i=0; i < n; i++) 
    {
      if (*p[i] > *maxVal) 
	maxVal = p[i];
    }
   return maxVal;
}


void print(float a[], int n)
{for(int i = 0; i < n; i++)
    cout << a[i] << " ";  
    cout << endl;  
}



int main ()
{
  const int SIZE = 5;
  float a[SIZE] = {11.0,22.0,33.0,44.0,55.0};
  cout << endl;    

  cout << "elements of the array are: " << endl;
  print(a,SIZE);

  float* p[SIZE];
  for(int i = 0; i < SIZE; i++)
    {  p[i] = &a[i];
      //cout << p[i] << "  ";
    }
  cout << endl;    


  // Returning maximum value
  float* max = getMax(p,SIZE);
  cout << "maximum of the array is  : " << *max << endl;

  return 0;
}





