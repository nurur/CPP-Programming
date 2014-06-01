// Problem: 6.23, chaper 6 (C++, J Hubbard)
// Reversing the elements of an Array
// No Sorting is necessary



#include <iostream>
using namespace std;


void reverse(float arr[], int size)
{
  float tmp[size];  

  int count = 0;
  for (int i = size-1; i >= 0; i--)
      {
	tmp[count] = arr[i]; 
	count++;
      } 
  
  for (int i = 0; i < size; i++)
    arr[i] = tmp[i];
}


void printA(float a[], int n)
{
  for(int i = 0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}




int main()
{
   const int SIZE = 10;
   float a[SIZE] = {55.5, 22.5, 99.9, 66.6, 44.4, 11.1, 88.8, 33.3, 44.4, 77.7};

  cout << "elements of the array are: " << endl;
  printA(a,SIZE);


  // Delete the first occurance of element from the Array
  int s = SIZE;
  reverse(a,s);
  printA(a,s);
 

  return 0;
}
