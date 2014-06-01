// Problem 7.16, chap 7 (C++, J R Hubbard)
// Sorting and Inserting using Array of Pointers 


#include <iostream>
using namespace std;


void swap(float& x, float& y)
{
  float t;
  t = x;
  x = y;
  y = t;
}


void sort(float* p[], int n)
// Sort the elements of the array 
{
  for (int i=1; i<n; i++)
    {
      for (int j=0; j<n-i; j++) 
	if (*p[j] > *p[j+1]) 
	  swap(*p[j], *p[j+1]);
    }
}


void insertUsingPtrToArr(float* arr[], int& size, float newElement)
// Insert an element using Pointer to Array as an argument 
{
  int position;
  
  // Find the position where the newElement needs to be inserted 
  for (int i=0; i<size-1; i++)
    if ( (newElement > *arr[i]) && (newElement < *arr[i+1]) ) 
      { 
	position = i+1; 
	break; 
      }
  
  cout << endl;
  cout << "The value of the newElement that is to be inserted: " 
       << newElement << endl;
  cout << "The location where the newElement to be inserted  : " 
       << position << endl;
  cout << "Shifting all elements from index " << position 
       << " and up ... ... ..." << endl;

  // Increase the index of each element that are to the right newElement  
  for (int j=size-1; j>=position; j--)    
    {    arr[j+1] = arr[j];	
      cout << "Shifting index: " << j+1 << " <-- " << j << endl;
    }
  cout << endl;

  //for (int k=indx; k>0; k--)    
  //  arr[k-1] = arr[k];	   

  // Insert newElement in the desired position 
  arr[position]= &newElement;    
  // Increase the array size
  ++size;                    

  // check 
  for (int i=0; i<size; i++)
    cout << i << "  " << *arr[i] << endl;  
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






int main()
{
   const int SIZE = 4;
   //float a[SIZE] = {55.5, 22.5, 99.9, 66.6, 44.4, 88.8, 33.3, 77.7};
   float a[SIZE] = {22.5, 66.6, 44.4, 33.3};

  cout << "The array elements are: " << endl;
  printA(a,SIZE);


  // Sort the Array
  float* p[SIZE];  // Array of (SIZE) Pointers to float
  for(int i=0; i<SIZE; i++)
    p[i] = &a[i]; 

  sort(p,SIZE);
  printP(p,SIZE);


  
  // Insert a New Element into the Array
  int   t = SIZE;
  float y = 28.4;
  insertUsingPtrToArr(p,t,y);
  printP(p,t);
  

  return 0;
}
