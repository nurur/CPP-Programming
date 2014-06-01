// Example 19.1
// Self-Test Exercises 1,2,3
// Vector Container


#include <vector>
#include <iostream>
using namespace std;



int main()
{
  vector<int> v;
  

  //create a vector container class 
  for (int i=1; i<=5; i++)
    v.push_back(i);
  

  cout << "Here is what is in the container v:\n";
  vector<int> :: iterator p;
  for (p=v.begin(); p != v.end(); p++)
    cout << *p << " ";
  cout << endl << endl;


  //Exercise 3
  //Wrting all the elements of p except the first element
  cout << "Wrting all the elements of the container v "
       << "except the first element:\n";
  for (p=v.begin(), p++; p != v.end(); p++)
    cout << *p << " ";
  cout << endl << endl;


  cout << "Setting entries to 0:\n";
  for (p=v.begin(); p != v.end(); p++)
    *p = 0;


  cout << "Container v now contains:\n";
  for (p=v.begin(); p != v.end(); p++)
    cout << *p << " ";
  cout << endl;

  return 0;
}
