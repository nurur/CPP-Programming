
#include <iostream>
using namespace std;


void inp(int **a, int x, int y)
{
  for (int i=0; i<x; i++)
    for (int j=0; j<y; j++)
      cin >> a[i][j];
  cout << endl;
}

void out(int **a, int x, int y)
{
  for (int i=0; i<x; i++)
    {   
      for (int j=0; j<y; j++)
	cout << a[i][j] << " ";
      cout << endl;
    }
}



int main()
{
   int x=0, y=0;
  cin >> x >> y;

  int **a = new int*[x];
  for (int i=0; i<x; i++)
    a[i] = new int[y];

  inp(a,x,y);
  out(a,x,y);


  return 0;
}
