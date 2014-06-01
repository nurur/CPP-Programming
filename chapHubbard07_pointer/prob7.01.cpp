// problem 7.1, chap 7 (C++, J R Hubbard)
// write a function that uses pointers to copy an array of double 
 

#include <iostream>
using namespace std;


double* copy(double [], int);
void print(double [],int);


int main ()
{
  int n;
  const int SIZE = 5;
  double a[SIZE] = {1,2,3,4,5};
  cout << endl;    

  print (a,SIZE);
  
  double* b  = copy(a,SIZE);
  a[0]= a[1] = 0;
  print (a,SIZE);
  print(b,SIZE);

  cout << endl;    
  return 0;
}



double* copy(double a[], int n)
{
  double* p = new double[n]; 
  for(int i = 0; i < n; i++)
    {p[i] = a[i];
     cout << p[i] << " ";
    }
  return p;
}


void print(double a[], int n)
{for(int i = 0; i < n; i++)
    cout << a[i] << " ";
    cout << endl;  
}
