// Example 
// Double Linked List
// Searching a node to anywhere in the List (first or middle)


#include <cstdlib>
#include <iostream>
using namespace std;


class DLIntNode
{
public:
  DLIntNode(){};
  DLIntNode(int theData, DLIntNode* thePrev, DLIntNode* theNext) 
    : data(theData), prev(thePrev), next(theNext) { }
  //
  DLIntNode(const DLIntNode& copy) 
  : data(copy.data)
  { 
    prev = (copy.prev ? new DLIntNode(*copy.prev) : NULL); 
    next = (copy.next ? new DLIntNode(*copy.next) : NULL); 
  }

  ~DLIntNode()
  { 
    //DLIntNode* tmpPrev =prev;
    DLIntNode* tmpNext =next;
    while(tmpNext !=0)
      {
	DLIntNode* next = tmpNext->getNextLink(); 
	delete tmpNext;
	tmpNext = next;
      }
    tmpNext=0; next=0;
  }

  int        getData()     const { return data; }
  DLIntNode* getPrevLink() const { return prev; }
  DLIntNode* getNextLink() const { return next; }

  void setData(int setData)        { data = setData; }
  void setPrevLink(DLIntNode* setPrevLink) { prev = setPrevLink; }
  void setNextLink(DLIntNode* setNextLink) { next = setNextLink; }

  DLIntNode* search(DLIntNode* head, int target);

private:
  int      data;
  DLIntNode* prev;
  DLIntNode* next;
};

typedef DLIntNode* DLIntNodePtr;


DLIntNode* DLIntNode :: search(DLIntNode* head, int target)
{
  DLIntNode* here = head;
  if (here == NULL) 
    {
      return NULL;
    }
  else
    {
      while (here->getData() != target && here->getNextLink() != NULL)
	here = here->getNextLink();
      
      if (here->getData() == target)
	return here;
      else 
	return NULL;
    } 
}



int main()
{
  const int SIZE = 9;
  int a[SIZE] = {14,18,7,15,5,11,9,3,2};

  // Note: p=List, q=Head
  DLIntNodePtr p;
  DLIntNodePtr q=NULL;
  for (int i=0; i<SIZE; i++) 
    { 
      p = new DLIntNode(a[i],NULL,q);
      if (i>0 && i<SIZE) 
	q->setPrevLink(p);       
      q = p;
    }

  cout << "The existing list is ... ... \n";
  for (int i=SIZE-1; i>=0; i--)
    cout << a[i] << " ";
  cout << endl;


  int target;
  cout << "Enter the number that needs to be searched: ";
  cin >> target;
 
  // Create a node 
  DLIntNodePtr here;
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
      cout << "The target match found at the node : "
	   << (p-here) << endl;  
    }

  // Release memory back to the freestore
  //for (int i=0; i<SIZE; i++) 
  //  { delete p; }
  // Make p and q as NULL pointers
  //p=0; q=0;
   

  return 0;
}
