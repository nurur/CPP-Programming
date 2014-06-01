// Example: 7.7
// Vector Class


#include <vector>
#include <iostream>
using namespace std;



int main()
{
  // check
  cout << "**************************************************\n";

  vector<int> v;
  cout << "Enter a list of positive numbers.\n" 
       << "Place a negative number at the end.\n";

  int next;
  cin >> next;

  while (next > 0)
    {
      v.push_back(next);
      cout << next << " added: ";
      cout << "v.size() = " << v.size() << endl;
      cin >> next;
    }
  
  cout << "You entered:\n";
  for (unsigned int i=0; i < v.size(); i++)
    cout << v[i] << " ";
  cout << endl;
  


  // check
  cout << "**************************************************\n";
  
  vector<int> w(15);
  unsigned int i;
  
  for (i=0; i < w.size(); i++)
    w[i] = i;
  
  vector<int> copy;
  copy = w;
  w[0] = 42;
  
  for (i=0; i < copy.size(); i++)
    cout << copy[i] << " ";
  cout<< endl;



  return 0;
}
