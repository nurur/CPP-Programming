// Example 19.5
// List Container
// List Container has Bi-directional iterator but does not has
// Random access iterator 


#include <list>
#include <iostream>
using namespace std;



int main()
{
  list<int> l;
  

  //create a list container class 
  for (int i=1; i<=5; i++)
    l.push_back(i);
  

  cout << "Here is what is in the container l:\n";
  list<int> :: iterator p;
  for (p=l.begin(); p != l.end(); p++)
    cout << *p << " ";
  cout << endl << endl;


  //Wrting all the elements of p except the first element
  cout << "Wrting all the elements of the container l "
       << "except the first element:\n";
  for (p = l.begin(), p++; p != l.end(); p++)
    cout << *p << " ";
  cout << endl << endl;


  cout << "Setting entries to 0:\n";
  for (p = l.begin(); p != l.end(); p++)
    *p = 0;


  cout << "Container l now contains:\n";
  for (p = l.begin(); p != l.end(); p++)
    cout << *p << " ";
  cout << endl;
  

  /*
  //List Container does not have Random access iterator   
  //Check:
  p = l.begin();
  cout << "The third entry is : " <<  l[2]  << endl;
  cout << "The third entry is : " <<  p[2]  << endl;
  cout << "The third entry is : " << *(p+2) << endl;
  cout<< endl;
  */


  //Bi-directional iterator 
  p = l.begin();
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
