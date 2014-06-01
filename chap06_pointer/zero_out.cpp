// use pointer, example 2  

#include <iostream>
using namespace std;

#define value 10

void zero_out_arr(int *arr, int n);
int a[value]={1,2,3,4,5,6,7,8,9,10};



int main()
{
  int i;
  zero_out_arr(a, value);
  
  //print out array elements
  for (i = 0; i < value; i++)
    {
      cout << a[i] << "  "; 
      //cout << a[i] << endl;
    }

  cout << endl;
  return 0;
}



void zero_out_arr(int *p, int n)
{  
  while (n-->0){
    *p = 0;
    p++;
  }
  
  //int i;
  //for (i = 0; i < n; i++){
  //*p = 0;
  //p++;
  //}
}


