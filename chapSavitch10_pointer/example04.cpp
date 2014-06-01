// Example : 10.8
// A function that returns an array   
// Subtle issue! 


#include <iostream>
using namespace std;


int* doubler(int a[], int size)
{
  int* tmp = new int[size];
  for (int i=0; i < size; i++)
    tmp[i] = 2*a[i];  

  return tmp;
}



int main()
{
  int a[] = {1, 2, 3, 4, 5};
  int* b  = doubler(a, 5);
  
  cout << "Array a: ";
  for (int i=0; i < 5; i++)
    cout << " " << a[i];   
  cout << endl;
  
  cout << "Array b: ";
  for (int i=0; i < 5; i++)
    cout << " " << b[i];  
  cout << endl;
  
  delete [] b;
  return 0;
}
