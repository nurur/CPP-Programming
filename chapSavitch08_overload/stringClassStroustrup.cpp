// Example 11.12, 
// chapter II, section 11 (The C++ Programming Language, B Stroustrup) 
// String Class 


#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;


class String 
{
  class Srep;
  Srep* rep;

public:
  String();
  String(const char*);
  String(const String&);
  String& operator=(const char*);
  String& operator=(const String&);
 ~String();

  class Cref;
  class Range { };
};


String ::  String()
{ rep = new Srep(0, ""); }

String ::  String(const char* c)
{ rep = new Srep(strlen(c), c); }

String ::  String(const String& s);
// Copy constructor 
{
  s.rep->n++;
  rep = x.rep;            // Share representation 
}

String& operator=(const char* c)
{
  if (rep-> == 1)                 // Recyle Srep
    rep->assign(strlen(c),c);
  else 
    {                             // Use new Srep
      rep->n++;
      rep = new Srep(strlen(c),c); 
    }
  return *this;
}

String& operator=(const String& s);
// Copy assignment operator 
{
  s.rep->n++;
  if (--rep->n == 0) delete rep;

  rep = x.rep;            // Share representation 
  return *this;
}


String :: Srep
{
  char* s;
  int sz;
  int z;


 private:
  Srep(const Srep&);
  Srep& operator=(const Srep&);
};
