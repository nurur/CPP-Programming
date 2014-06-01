// Example : 
// Self-test Exercise 10.10, 10.12


#include <iostream>
using namespace std;


int main()
{
  // check: self-test exercise 10 
  int *wholeNum;
  wholeNum = new int[15];
  
  int i = 0;
  int n;
  cout << "Filling the array whloeNum:\n";
  while (i < 15)
    { cin >> n;
      wholeNum[i] = n;
      i++;
    }

  cout << "Array wholeNum: ";
  for (int i=0; i < 15; i++)
    cout << " " << wholeNum[i];   
  cout << endl;


  // check: self-test exercise 12 
  int arrInt[5];
  int arraySize = 5;
  int* ptr = arrInt;

  for (int i=0; i < arraySize; i++)
    arrInt[i] = 2*i;
  
  for (int i=0; i < arraySize; i++)
    cout << ptr[i] << " ";
  
  
  cout << endl;  
  return 0;
}
