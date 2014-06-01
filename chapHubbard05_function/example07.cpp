// EXAMPLE
// Pass by value of address 
// Return by address


#include <iostream>
using namespace std;


// case 1:
int* AllocateArray1(int x)
{
  int* p = new int[x];
  return p;
}


// case 2:
int* AllocateArray2(int* x)
{
  //return x;
  int* p = x;
  return p;
}


// case 3: 
int* AllocateArray3(int* x, int n)
{
  int* tmp = new int[n];
  int* p = (x+n)-1;

  int i=0;
  for (p; p >= x ; p--)
    {
      tmp[i] = *p;
      i++;
    }

  return tmp;
}


 

int main()
{
  const int SIZE=5;
  int* pnArray = AllocateArray1(SIZE);
   for (int i=0; i < SIZE; i++)
    cout << pnArray[i] << " ";
  
  delete[] pnArray;
  cout << endl;
  
  

  int myArray[SIZE] = {1,2,3,4,5};
  int* pn2 = AllocateArray2(myArray);
  for (pn2; pn2 < myArray+SIZE; pn2++)
    cout << *pn2 << " ";
  cout << endl;
  
  

  int* pn3 = AllocateArray3(myArray, SIZE);
  for (int i=0; i < SIZE; i++)
    cout << pn3[i] << " ";

  delete[] pn3;
  cout << endl;
  
 
  
  return 0;
}
