// Example 19.3
// Vector Container
// Reverse iterator 


#include <vector>
#include <iostream>
using namespace std;


int main()
{
  vector<char> v;
  
  //create a vector container class 
  v.push_back('A');
  v.push_back('B');
  v.push_back('C');
  v.push_back('D');
  v.push_back('E');
  

  //Print as it is  
  vector<char> :: iterator p;
  for (p = v.begin(); p != v.end(); p++)
    cout << *p << " ";
  cout << endl;
  
  
  //Print in reverse order
  vector<char> :: reverse_iterator rp;
  for (rp = v.rbegin(); rp != v.rend(); rp++)
    cout << *rp << " ";
  cout << endl;


  return 0;
}
