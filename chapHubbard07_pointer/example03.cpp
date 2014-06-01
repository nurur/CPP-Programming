// EXAMPLE 7.9 
// Returning a reference by a function 

#include <iostream>
using namespace std;


float& component(float* v, int k)
{
  return v[k-1];
}
 


int main()
{
  int i, k;
  const int SIZE=5;
  float v[SIZE] = { };
   

  //for (k=1; k <= 5; k++)
  //  v[k-1] = 1./k;
  for (k=1; k <= SIZE; k++)
    component(v,k) = 1./k;


  for (i=0; i < SIZE; i++)
    cout << "v" << "[" << i << "]: " << v[i]<< endl;
  

  return 0;
}
