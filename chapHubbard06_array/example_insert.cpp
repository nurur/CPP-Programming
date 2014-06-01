// Problem 6.17, chaper 6 (C++, J Hubbard)
// Insert a new element in the exiting array


#include <cstdlib>
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


void insertUsingArray(float arr[], int& size, float newElement)
// Method 1
// Find the the position where the new elemnet should be inserted
// Then move the array elements that are on the right side of the 
// new element array 
// That is: move index of each of those elements 1 up to the right 
{
  int i, j, indx;  

  for (int i=1; i<size-1; i++)
    if ( (newElement > arr[i]) && (newElement < arr[i+1]) ) 
      {
	indx = i+1; break;
      }

  for (j=size-1; j>=indx; j--)    
      arr[j+1] = arr[j];	 
  arr[indx]= newElement;  
  ++size;
}


void insertPosition(float arr[], int& size, float newElement)
// Method 2
// Caution: I don not know where to place the delete operator! 
{
  int i, j, position;

  for (i=1; i<size-1; i++)
    if ( (newElement > arr[i]) && (newElement < arr[i+1]) ) 
      {
	position = i+1; break;
      }
  
  float* tmp = new float[size+1];
  for(j = 0; j < size; j++)
    tmp[j] = arr[j];
  
  for(j = size-1; j >= position; j--)
    tmp[j+1] = tmp[j];
  tmp[position] = newElement;
  ++size;
  
  // Assigned the pointer location of tmpArr to arr
  //arr = tmp;                    // Does not work!
  for(j = 0; j < size; j++)
    arr[j] = tmp[j];                    
  
  /*
  // Check : print array elements  
  cout << endl;
  cout << "----- Inside insertPosition() Function ----- \n";
  for (i=0; i<size; i++)
  cout << arr[i] << " " <<  tmp[i] << endl;
  cout << endl;
  cout << "-------------------------------------------- \n";
  cout << endl;
  */  
}


void printA(float a[], int n)
{
  for(int i=0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}




int main()
{
   const int SIZE = 8;
   float a[SIZE]  = {55.5, 22.5, 99.9, 66.6, 44.4, 88.8, 33.3, 77.7};
   float b[SIZE]  = {55.5, 22.5, 99.9, 66.6, 44.4, 88.8, 33.3, 77.7};

  cout << "The array elements are: " << endl;
  printA(a,SIZE);


  // Method 1
  // First, sorting an Array
  bubbleSort(a,SIZE);
  printA(a,SIZE);
  
  // Next, insert an Element into the Array
  float x = 38.4;
  int   s = SIZE;
  insertUsingArray(a,s,x);
  printA(a,s);
 


  // Method 2
  // First, sorte the Array
  // Next, insert the new element into the Array
  bubbleSort(b,SIZE);

  float y = 38.4;
  int   t = SIZE;
  insertPosition(b,t,y);
  printA(b,t);

  return 0;
}
