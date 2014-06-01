// Example 17.10, 17.11
// Double Linked List
// Deleting a node to anywhere in the List (first or middle)


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


private:
  int      data;
  DLIntNode* prev;
  DLIntNode* next;
};


typedef DLIntNode* DLIntNodePtr;



int main()
{
  const int SIZE = 6;
  int a[SIZE] = {5,9,4,6,1,2};

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



  int nodeNumber;
  cout << "Enter the number of the node that will be \n" 
       << "deleted (starting from 1) : "; 
  cin >> nodeNumber;
  cout << endl;

  // Create temporary nodes immediately before and after 
  // The node that will be deleted 
  DLIntNodePtr discard; 
  DLIntNodePtr prev, next;
  // Assign the head of the existing List to discard 
  discard = p;                      

  // Find the node before the one that will be deleted
  if (nodeNumber == 1)
    {  
      discard = discard->getNextLink(); // Go to the second Node
      discard->setPrevLink( NULL );     // Set the Second node as the First 
      p = discard;
    }

  if (nodeNumber > 1)
    {
      for (int i=1; i<nodeNumber; i++)
	{ 
	  discard = discard->getNextLink(); // Go to the Node that 
	                                    // will be deleted 	  
	  
	  prev = discard->getPrevLink();    // Find the Previous Node 
	  next = discard->getNextLink();    // Find the Next Node  
	}
      
      if( next == NULL )
	{ 
	  cout << "Node " << nodeNumber 
	       << " does not exist!\n" 
	       << "Aborting ... ...\n";
	  exit(1);
	}
      else
	{
	  prev->setNextLink(next);  // connect prev Node to the next Node 
	  next->setPrevLink(prev);  // connect next Node to the prev Node       
	}   
    }
  
  // Print the new List 
  cout << "The revised list is ... ... \n";
  while ( p != NULL )
    { 
      cout << p->getData() << " ";
      p = p->getNextLink();
    }

  cout << endl;
  return 0;
}
