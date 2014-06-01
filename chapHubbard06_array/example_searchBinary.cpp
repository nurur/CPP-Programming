// Example 6.14
// Binary Search Algorithm


#include <iostream>
using namespace std;


int index(int a[], int n, int x)
{
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
  // Single occurance of each elements 
  const int SIZE = 10;
  int a[SIZE] = {22, 44, 66, 88, 38, 11, 33, 55, 77, 99};

  cout << "Single occurance of each element of the array  : " << endl;
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
  cout << endl << endl;



  // Multiple occurances of some elements 
  int b[SIZE] = {22, 44, 66, 77, 38, 11, 33, 55, 77, 99};

  cout << "Multiple occurances of some elements of the array: " << endl;
  cout << "The elements of the array are: " << endl;
  printA(b,SIZE);
  cout << endl;

  cout << "Sorting the array ... ... ... " << endl;
  bubbleSort(b,SIZE);
  printA(b, SIZE);
  cout << endl;

  int m = 77;
  int n = 72;
  cout << "Array index(a,SIZE,11) is : " << index(a,SIZE,m) << endl;
  cout << "Array index(a,SIZE,72) is : " << index(a,SIZE,n) << endl;

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

