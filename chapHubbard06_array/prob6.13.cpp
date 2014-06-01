// Problem: 6.13, chaper 6 (C++, J Hubbard)
// Deleting the first occurance of an element from an Array
// No Sorting is necessary



#include <iostream>
using namespace std;


void deleteFirst(float arr[], int& size, float deleteElement)
// Find the the position from where the elemnet should be deleted
// Then move the array elements down by one index that are on the 
// right side of the deleted element 
{
  int indx[10] = { 0 };  
  int count = 0 ;
  for (int i=0; i<size; i++)
    if ( deleteElement == arr[i] )
      {
	indx[count] = i; 
	count++;
      } 

  for (int j=indx[0]; j<size-1; j++)  
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
   const int SIZE = 10;
   float a[SIZE] = {55.5, 22.5, 99.9, 66.6, 44.4, 11.1, 88.8, 33.3, 44.4, 77.7};

  cout << "elements of the array are: " << endl;
  printA(a,SIZE);


  // Delete the first occurance of element from the Array
  float x = 44.4;
  int   s = 10;
  deleteFirst(a,s,x);
  printA(a,s);
 

  return 0;
}
