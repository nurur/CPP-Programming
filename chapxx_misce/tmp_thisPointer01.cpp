// Example:  This pointer
// http://www.learncpp.com/cpp-tutorial/87-the-hidden-this-pointer/


#include <iostream>
using namespace std;


class Simple
{
public:
  Simple();
  Simple(int nID);
  
  void SetID(Simple* const THIS, int nID); 
  int  GetID(Simple* const THIS);

private:
    int m_nID;
};


inline Simple :: Simple() { m_nID = 0; }

inline Simple :: Simple(int nID) { m_nID = nID; }

void Simple :: SetID(Simple* const THIS, int nID) 
{ THIS->m_nID = nID; }

int Simple :: GetID(Simple* const THIS) 
{ return (THIS->m_nID); }


	
int main()
{
    Simple x(1);
    x.SetID(&x,2);
    cout << x.GetID(&x) << endl;

    return 0;
}
