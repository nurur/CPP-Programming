// EXAMPLE: 8.8 
// cin.putback() and cin.ignore() functions
// text: what is 305 plus 9416, can you tell?


#include <iostream>
using namespace std;

int nextInt();


int main ()
{
  int m = nextInt();
  int n = nextInt();

  //cin.ignore(80,'\n');
  cout << m << " + " << n << " = " << m+n << endl;
  
  return 0;
}



int nextInt()
{ char ch;
  int n;

  while (cin.get(ch))
    if (ch >= '0' && ch <= '9')
      {cin.putback(ch);
	cin >> n;
	break;
      }

  return n;
}
