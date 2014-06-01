// Problem 7.9, chap 7 (C++, J R Hubbard)


#include <iostream>
using namespace std;


char* strCopy(char* s1, const char* s2)
{
  while(*s2 !='\0')
    cout << *s1++ << "  " << *s2++ << endl; //*s1++ = *s2++;
  //*s1 = 0;
  return s1;
}


void charCopy(char* s1, const char* s2)
{
  char* p= s1;
  // unsigned lenS1 = 0;
  // for (p; *p !='\0'; p++)
  //  lenS1++;

  const char* q = s2;
  unsigned lenS2=  0;
  for (q; *q !='\0'; q++)
    lenS2++;
  

  // for(q; *q != '\0'; q++)
  //  {if (*s2)
      //cout << *s1 << "  " << *s2 << endl;
      //*s1++ = *s2++;
  //  }


  int i=0;
  for(i; i<lenS2; i++)
    { if (s2[i] != '\0')
	//s1[i] = s2[i];
      cout << s1[i] << "  " << s2[i] << endl;
    }


  //i =0;
  //for(i; i<lenS2+3; i++)
  //  cout << s1[i] << endl;

  //cout << lenS1 << endl;
  //cout << lenS2 << endl;
}



int main ()
{
  char* s1       = "Nurur";
  const char* s2 = "Rahma";
  charCopy(s1,s2);	    
  cout << s1 << " ... " << s2 << endl;

  //char* s3 = strCopy(s1,s2);
  //cout << s1 << " ... " << s2 << " ... " << s3 << endl;

  return 0;
}
