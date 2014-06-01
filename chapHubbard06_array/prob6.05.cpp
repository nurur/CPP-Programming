// Problem 6.5,  chaper 6 (C++, J Hubbard)
// Modification of Example 6.11
// Prining memory address and content of an array 


#include <iostream>
using namespace std;


int main()
{
  const int SIZE = 10;
  int a[10] = {22, 44, 66, 88, 44, 11, 33, 55, 11, 99};

  cout << "Printing memory addresses ... ... " << endl;
  for (int i=0; i<SIZE; i++)
    cout<< "a["<< i <<"] = " << (a+i) << endl;

  cout << "Printing contents ... ... ... ..." << endl;
  for (int i=0; i<SIZE; i++)
    cout<< "a["<< i <<"] = " << *(a+i) << endl;

  return 0;
}
