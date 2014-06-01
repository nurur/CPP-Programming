// EXAMPLE 7.15
// Dynamic Array 
// Pass by value of address 
// Pass by reference of address 


#include <iostream>
using namespace std;


// Pass by reference of address 
void get(double*& rp, int& n)
{
  cout << "Enter number of items : "; cin >> n;

  rp = new double[n];

  cout << "Enter " << n << " items, one per line : \n";
  for(int i = 0; i < n; i++)
    {  
      cout << "\t" << i+1 << ": ";
      cin >> rp[i];
    }
}


// Pass by value of address 
void print(double* p, int n)
{
   if (!p)
     return;
   
  for(int i = 0; i < n; i++)
    cout << p[i] << " ";
  cout << endl;  
}



int main ()
{
  doublePtr a;
  int n;
  
  get(a,n);
  print(a,n);
  cout << endl;  

  delete[] a;
    
  get(a,n);
  print(a,n);
  cout << endl;  
  
  return 0;
}



