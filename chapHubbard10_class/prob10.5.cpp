// Problem 10.6
// String Class 


#include <cstring>
#include <iostream>
using namespace std;


class String 
{
public :
  String(int);                                      // default constructor
  String(char*);                                    // constructor 
  String(const String&);                            // copy constructor
 ~String() { delete [] data; }                      // destructor 

  char* name() { return data; }                     // access function
  int length() { return  len; }

  void   print();

private:
  int    len;  // number of non-null character in the "data"
  char* data;
};




int main()
{
  //String S;
  //S.print();

  String S2("John");
  S2.print();

  cout << endl;
  return 0;
}



// default constructor
String :: String(int size) : len(size)
{
  data = new char[len+1];
  for (int i = 0; i < len; i++)
    data[i] = ' ';  
  data[len] = '\0';
}

// constructor 
String :: String(char* str) : len(strlen(str))
{
  data = new char[len+1];
  memcpy(data, str, len+1);
}

// copy constructor 
String :: String(const String& str) 
  : len(str.len)
{
  data = new char[len+1];
  memcpy(data, str.data, len+1);
}

void String :: print()
{cout << "data    : " << data << endl;}


