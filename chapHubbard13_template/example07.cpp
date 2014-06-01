// Example: 
// Sequence Template

#include <iostream>
using namespace std;


template <class T, int N>
class mySequence 
{
public:
  void setmember (int x, T value);
  T getmember (int x);

private:
  T memblock [N];
};


template <class T, int N>
void mySequence<T,N> :: setmember (int x, T value) { memblock[x] = value; }

template <class T, int N>
T mySequence<T,N> :: getmember (int x) { return memblock[x]; }



int main () {
  mySequence <int,5>      myints;
  mySequence <double,5> myfloats;
  
  myints.setmember   (0,100);
  myfloats.setmember (3,3.1416);
  cout << myints.getmember(0)   << '\n';
  cout << myfloats.getmember(3) << '\n';

  cout << endl;
  return 0;
}
