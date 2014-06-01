
#include <string>
#include <cstring>
#include <iostream>
using namespace std;


class X 
{
private:
  int len;
  char *ptr;
  
public:
  int   GetLen (X* const THIS) { return THIS->len; }
  char* GetPtr (X* const THIS) { return THIS->ptr; }
  
  X&  Set(X* const, const char*);
  X&  Cat(X* const, const char*);
  X& Copy(X* const, X&);

  void Print(X* const);
};



X& X::Set(X* const THIS, const char* pc) {
  THIS->len = strlen(pc);
  THIS->ptr =  new char[THIS->len];
  strcpy(THIS->ptr, pc);
  return *THIS;
}

X& X::Cat(X* const THIS, const char* pc) {
  THIS->len += strlen(pc);
  strcat(THIS->ptr, pc);
  return *THIS;
}

X& X::Copy(X* const THIS, X& x) {
  THIS->Set(THIS, x.GetPtr(&x));
  return *THIS;
}

void X::Print(X* const THIS) {
  cout << THIS->ptr << endl;
}



int main() {
  X xobj1;
  xobj1.Set(&xobj1 , "abcd")
       .Cat(&xobj1 , "efgh");

  xobj1.Print(&xobj1);


  X xobj2;
  xobj2.Copy(&xobj2 , xobj1)
       .Cat(&xobj2 , "ijkl");

  xobj2.Print(&xobj2);
}
