// Problem: 6.21  chaper 6 (C++, J Hubbard)
// Counting frequency of occurance of an array element 


#include <iostream>
using namespace std;


int frequency(float a[], int n, float x)
{
  int count, indx; 
  
  count = 0;
  for (int i=0; i<n; i++) 	
    { 
      if ( a[i] == x ) 
	++count;
    }
  return count; 
}


void printA(float a[], int n)
{
  for(int i = 0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}




int main()
{
  const int SIZE = 8;
  float a[SIZE] = {55.5, 22.5, 99.9, 66.6, 44.4, 88.8, 33.3, 77.7};
  
  cout << "The array elements are ... " << endl;
  printA(a,SIZE);
  

  float x   = 77.7;
  int count = frequency(a, SIZE,x);
  cout << "Frequency of the number is: " << count << endl;


  return 0;
}
