// Example 6.9 , chaper 6 (C++, J Hubbard)
// Passing an Array to a Function 


#include <iostream>
using namespace std;



int sum1(int a[], int n)
// Method 1
{ 
  int sum = 0;
  for (int i=0; i<n; i++)
    sum += a[i];

  return sum;
} 



int sum2(int* p, int n)
//Method 2
{ 
  int sum = 0;
  for (int i=0; i<n; i++)
    sum += p[i];

  return sum;
} 




int main()
{
  int a[] = {11, 33, 55, 77};
  int size = sizeof(a)/sizeof(a[0]);

  cout << "Sum : " << sum1(a,size) << endl;
  cout << "Sum : " << sum2(a,size) << endl;

  return 0;
}
