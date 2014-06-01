//Example 
// Five different types of iterators 


#include <vector>
#include <iostream>
using namespace std;



int main()
{
  vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(3);
  v.push_back(4);
  v.push_back(5);

  vector<int> :: iterator p;
  vector<int> :: iterator begin = v.begin();
  vector<int> :: iterator end = v.end();

  //input perator
  for (p = begin; p < end; p++)
    cout << *p << " ";
  cout<< endl;

  //forward perator 
  for (p = begin; p < end; p++)
    cout << *p << " ";
  cout<< endl;

  //bi-directional iterator -- iterates backward
  for (p -= 1; p >= begin; p--)
    cout << *p << " ";
  cout<< endl;
 
  //random access iterator 
  p = begin + 2;
  cout << *p << " ";
  p += 2;
  cout << *p << " ";
  p -= 2;
  cout << *p << " ";
  cout<< endl;
 
  //output iterator
  for (p = begin; p < end; p++)
    *p = 0;
  for (p = begin; p < end; p++)
    cout << *p << " ";
  cout<< endl;
  

  return 0;
}
