// Example 17.8, 17.9
// Single Linked List
// Searching a List for a target number 


#include <cstdlib>
#include <iostream>
using namespace std;


class SLIntNode
{
public:
  SLIntNode(){};
  SLIntNode(int theData, SLIntNode* theLink) 
  : data(theData), link(theLink) { }

  // COPY CONSTRUCTOR 
  SLIntNode(const SLIntNode& copy) 
  : data(copy.data)
  { link = (copy.link ? new SLIntNode(*copy.link) : NULL); }

 // DESTRUCTOR
  ~SLIntNode()
  { 
    SLIntNode* current =link;
    while(current !=0)
      {
	SLIntNode* tmp = current->getLink(); 
	delete current;
	current = tmp;
      }
    current=0; link=0;
  }

  int        getData() const { return data; }
  SLIntNode* getLink() const { return link; }

  void setData(int setData)        { data = setData; }
  void setLink(SLIntNode* setLink) { link = setLink; }

  SLIntNode* search(SLIntNode* head, int target);

private:
  int      data;
  SLIntNode* link;
};


SLIntNode* SLIntNode :: search(SLIntNode* head, int target)
{
  SLIntNode* here = head;

  //Method 1
  if (here == NULL)  return NULL;  
  while (here != NULL)
    {
      if (here->getData() != target)
	here = here->getLink();
      else if (here->getData() == target)
	return here;	  
      else 
	return NULL;
    } 

  /*Method 2
  if (here == NULL)  return NULL;  
  while (here->getData() != target && here->getLink() != NULL)
    here = here->getLink();
  
  if (here->getData() == target)
    return here;
  else 
    return NULL;
  */
}

typedef SLIntNode* SLIntNodePtr;




int main()
{
  const int SIZE = 10;
  int a[SIZE] = {1,18,7,15,5,11,9,3,2,23};

  // Note: p=List, q=Head
  SLIntNodePtr p;
  SLIntNodePtr q=NULL;
  for (int i=0; i<SIZE; i++) 
    { 
      p = new SLIntNode(a[i],q);
      q = p;
    }

  cout << "The existing list is ... ... \n";
  for (int i=SIZE-1; i>=0; i--)
    cout << a[i] << " ";
  cout << endl;


  int target;
  cout << "Enter the number that needs to be searched: ";
  cin >> target;
  cout << endl;

  // Create a node 
  SLIntNodePtr here;
  // Get the search result             
  here = here->search(p,target);
  // Print the search result 
  if (here == NULL)
    {
      cout << "The target number " << target
	   << " is not in the list.\n"
	   << "No match found.\n";
    }
  else
    {
      cout<< "The node count starts from 0" << endl;
      cout << "The target match found at the node: "
	   << (p-here)/2 << endl;  
    }

  
  // Release memory back to the freestore
  // for (int i=0; i<SIZE; i++) 
  //  { delete p; }
  // Make p and q as NULL pointers
  //p=0; q=0;
  
  return 0;
}
