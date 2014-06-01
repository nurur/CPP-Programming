// Example 19.2
// Vector Container
// Random access and Bi-directional iterators 


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

  for (int i=0; i<5; i++)
    cout << "Container [" << i << "] : " << v[i] << endl;
  cout<< endl;


  //Random access iterator   
  vector<char> :: iterator p;
  p = v.begin();
  cout << "The third entry is : " <<  v[2]  << endl;
  cout << "The third entry is : " <<  p[2]  << endl;
  cout << "The third entry is : " << *(p+2) << endl;
  cout<< endl;


  //Bi-directional iterator 
  p = v.begin();
  cout << "Back to container v[0], which has value : " << *p << endl;
  
  cout << "Two steps forward: \n";
  p++;
  cout << *p << endl;
  p++;
  cout << *p << endl;

  cout << "One step backward: \n";
  p--;
  cout << *p << endl;

  return 0;
}
