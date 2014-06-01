// Problem: 6.24,  chaper 6 (C++, J Hubbard)
// Finding (symmetric or asymmetric) nature of an array


#include <iostream>
using namespace std;


bool isSymmetric(float a[], int n)
{
  float b[n];
  
  int j = 0;
  for (int i=n-1; i>0; i--) 	
    {
      b[j] = a[i];
      ++j;
    }
  
  if (a[0] == b[0]) return true;
  else return false;
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
  
  cout << "The array elements are ...  " << endl;
  printA(a,SIZE);

  bool arrType; string s;
  arrType = isSymmetric(a,SIZE);
  if (arrType) s = "Symemtric";
  else s = "Asymmetric";

  cout << "This is an " << s << " array" << endl;

  return 0;
}
