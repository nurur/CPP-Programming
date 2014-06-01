// Problem: 6.12, chaper 6 (C++, J Hubbard)
// Sorting an Array 
// Deleting an element from a sorted array



#include <iostream>
using namespace std;


void swap(float& x, float& y)
{
  float tmp;
  tmp = x;
  x   = y;
  y   = tmp;
}


void bubbleSort(float p[], int n)
{
  for (int i=1; i<n; i++)
    {
      for (int j=0; j<n-i; j++) 
	
	if (p[j] > p[j+1])
	  swap(p[j], p[j+1]);
    }
}


void delete(float arr[], int& size, float deleteElement)
// Find the the position from where the elemnet should be deleted
// Then move the array elements down by one index that are on the 
// right side of the deleted element 
{
  int indx;  
  for (int i=0; i<size; i++)
    if ( deleteElement == arr[i] )
      {
	indx = i; break;
      }
  
  for (int j=indx; j<size-1; j++)  
    arr[j] = arr[j+1];	 
  --size;
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

  cout << "elements of the array are: " << endl;
  printA(a,SIZE);


  // First, sort the array
  bubbleSort(a,SIZE);
  printA(a,SIZE);

  // Next, Delete the specific element from the array
  float x = 44.4;
  int   s = 8;
  delete(a,s,x);
  printA(a,s);
 

  return 0;
}
