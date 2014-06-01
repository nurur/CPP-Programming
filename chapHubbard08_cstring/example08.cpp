// EXAMPLE: 8.13, 8.14 
// C-String functions


#include <cstring>
#include <iostream>
using namespace std;


int main ()
{
  char c[] = "ABCDEFG";
  cout << "strlen, c     : " << strlen(c) << endl;


  char s[] = "The Missisipi is a Long River";
  cout << "strlen, s     : " << strlen(s)    << endl;
  cout << endl;

  char* p = strchr(s,' ');
  cout << "strchr (s,' '): " << p-s << endl;


  //strtok()
  char cc[] = "###ABCD#EFG##HIJK#L#MN#####O#P####";
  cout << "before, the string is: " << cc << endl;
  
  char *pp = strtok(cc,"#");

  char* ss[7];
  int count = 0;
  while (pp)
    { cout << "[" << pp << "]\n";
      ss[count] = pp;
      ++count;
      
      pp = strtok(NULL,"#");
    }
  cout << "after , the string is: " << cc << endl;
  
  for (int i = (count-1); i > -1 ; i--)
    cout << ss[i] << " ";
  

  /*
  char cc[] = "ABCDEFG";
  char*  ss = "ABCDEFG";
  cout << cc << "  " << ss << endl;
  */

  cout << endl;
  return 0;
}
