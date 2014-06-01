// Example:
// Counting 1's and 0's from a binary number 
 

#include <cstring>
#include <iostream>
using namespace std;



int main()
{

  char c[10];
  cin >> c;

  int i;
  for (i=0; i<sizeof(c) ; i++)
    { 
      if (c[i] == '\0') break;
      i++;
    } 
  
  int size = i;
  cout << size << endl; 

  int  oneCount=0;
  int zeroCount=0;
  for (i =0; i<size; i++)
    {
      if (c[i] == '1') 
	{
	  oneCount++;
	  cout << c[i] << " ";
	}
      else zeroCount++;
    }
  cout << endl;
  
  cout << "# of 1s = " <<  oneCount << endl;
  cout << "# of 0s = " << zeroCount << endl;
  return 0;
}
