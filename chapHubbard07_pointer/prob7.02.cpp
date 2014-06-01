// problem 7.2, chap 7 (C++, J R Hubbard)
// write a function that uses pointers to search the address of a given 
// interger in a given array
 

#include <iostream>
using namespace std;


int* location(int [], int, int);

int main ()
{
  int  n; 
  int* p;
  const int SIZE = 5;
  int a[SIZE] = {11,22,33,44,55};
  cout << endl;    
  
  cout << "enter a positive integer: ";
  
  do {
    cin >> n;    
    if (p = location(a,SIZE,n)) cout << p << ", " << *p << endl;
    else cout << n << " is not found" << endl;
     } while (n > 0);
  
  cout << endl;    
  return 0;
}



int* location(int a[], int n, int target)
{
  for(int i = 0; i < n; i++)
    if (a[i] == target) return &a[i];
  
  return NULL;  
}
