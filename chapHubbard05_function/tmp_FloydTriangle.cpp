// Example 
// Floyd's Triangle 


#include <iomanip>
#include <iostream>
using namespace std;


int main()
{
  int const m = 11;
  
  int n=1;
  for (int i=1; i<m; i++)
    {
      for (int k=0; k<m-i; k++)
	cout << setw(2) << " ";
      for (int j=0; j<i; j++)
	{	
	  cout << setw(4) << n;
	  n++;
	}
      cout << endl;
    }

  return 0;
}
