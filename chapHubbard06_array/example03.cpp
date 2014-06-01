// Example 6.16
// Binary Search Algorithm 
// With assert() function


#include <cassert>
#include <iostream>
using namespace std;


bool isNondecreasing(int a[], int n)
// Returns true iff a[0] <= a[1] <= a[2] ...
{
  for (int i=0; i<n; i++)
    if (a[i] > a[i+1]) return false;
  return true;
}


int index(int a[], int n, int x)
{
  // Check the order of the array 
  // Abort, if the array is not sorted in ascending order
  assert( isNondecreasing(a, n) ); 


  int first, last, middle;
  first = 0;
  last  = n-1;

  int indx   = 0;
  bool found = false;

  while (first <= last)
    {
      middle = (first + last)/2;
      //cout << first << " " << last << " " << middle << " ";
      if (x == a[middle]) 
	{ 
	  indx  = middle; 
	  found = true;
	}
      if (x  > a[middle]) first = middle+1;
      if (x  < a[middle]) last  = middle-1;
      
      if (found) return indx;
    }
  
  if (!found) 
    { 
      cout << "The object is not found.\n"; 
      return -1;             
    }

}



void swap(int&, int&);
void bubbleSort(int [], int);
void printA(int [], int);


int main()
{
  const int SIZE = 10;
  int a[SIZE] = {22, 44, 66, 88, 38, 11, 33, 55, 77, 99};

  cout << "The elements of the array are: " << endl;
  printA(a,SIZE);
  cout << endl;

  cout << "Sorting the array ... ... ... " << endl;
  bubbleSort(a,SIZE);
  printA(a, SIZE);
  cout << endl;

  int x = 33;
  int y = 60;
  cout << "Array index(a,SIZE,33) is : " << index(a,SIZE,x) << endl;
  cout << "Array index(a,SIZE,60) is : " << index(a,SIZE,y) << endl;

  return 0;
}



void swap(int& x, int& y)
{
  float t;
  t = x;
  x = y;
  y = t;
}


void bubbleSort(int a[], int n)
{
  for (int i=1; i<n; i++)
    for (int j=0; j<n-i; j++) 
      { 
	if (a[j] > a[j+1])
	  swap(a[j], a[j+1]);
      }
}


void printA(int a[], int n)
{
  for(int i = 0; i<n; i++)
    cout << a[i] << " ";  
  cout << endl;  
}

