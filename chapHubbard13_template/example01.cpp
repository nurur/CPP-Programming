// Example: 13.1, 13.2
// Function Template 
// Max Function, Swap Function, Sort Function  


#include <iostream>
using namespace std;


template <class T>
T GetMax (T a, T b) 
{ return (a>b ? a : b); }


template <class T>
void swapValues(T& x, T& y)
{T tmp;
  tmp = x;
  x   = y;
  y = tmp;
}


template <class T>
void sortValues(T* v, int n)
{for (int i = 1; i < n; i++)
    for (int j = 0; j < n-i; j++)
      if (v[j] > v[j+1]) 
	swapValues(v[j], v[j+1]);		   
}


template <class T>
void print(T* v, int n)
{for (int i = 0; i < n; i++)
    cout << " " << v[i];
  cout<< endl;
}




int main()
{
  int m = 22, n = 44;
  cout << "before: m :" << m << ", n :" << n << endl;
  swapValues(m,n);
  cout << "after : m :" << m << ", n :" << n << endl;


  short a[9] ={55,33,88,11,44,99,77,22,66};
  cout << "before: "; print(a, 9);
  sortValues(a, 9);
  cout << "after : "; print(a, 9);
 

  string s[7] = {"Tom","Hal","Dan","Bob","Sue","Ann","Gus"};
  cout << "before: "; print(s, 7);
  sortValues(s, 7);
  cout << "after : "; print(s, 7);
 

  cout << endl;
  return 0;
}
