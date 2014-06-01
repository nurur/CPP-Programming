// Example
// Deque Container
// illustrating push_front() and push_back() functions 


#include <deque>
#include <iostream>
using namespace std;


int main()
{ 
  deque<int> deq;
  for (int nCount=0; nCount < 4; nCount++)
    {
      deq.push_back(nCount);       //insert at end of array
      deq.push_front(10 - nCount); //insert at front of array
    }
  
  for (int nIndex=0; nIndex < deq.size(); nIndex++)
    cout << deq[nIndex] << " ";
  
  cout << endl;
}
