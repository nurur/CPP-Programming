// Example 17.10, 17.11
// Double Linked List
// Constructing doubly Linked List
// Making a deep copy of the List 
// Adding node at the begining of the List
// Forward traversing the new List 
// Backward traversing the old List 


#include <iostream>
using namespace std;


class DLIntNode
{
public:
  DLIntNode(){};
  DLIntNode(int theData, DLIntNode* thePrev, DLIntNode* theNext) 
    : data(theData), prev(thePrev), next(theNext) { }

  //COPY CONSTRUCTOR 
  DLIntNode(const DLIntNode& copy) 
  : data(copy.data)
  { 
    prev = (copy.prev ? new DLIntNode(*copy.prev) : NULL); 
    next = (copy.next ? new DLIntNode(*copy.next) : NULL); 
  }

  //DESTRUCTOR
  ~DLIntNode()
  { 
    //IntNode* tmpPrev =prev;
    DLIntNode* tmpNext =next;
    while(tmpNext != 0)
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
  const int SIZE = 10;
  int a[SIZE] = {1,18,7,15,5,11,9,3,2,23};

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
  cout << endl << endl;


  // Make a Deep Copy of the List
  DLIntNodePtr p1 = p;
  DLIntNodePtr p2 = p;
  cout << "Printing the deep copy of the List ... \n";
  while ( p1 != NULL )
    { 
      cout << p1->getPrevLink() << " " 
	   << p1->getData()     << " " 
	   << p1->getNextLink() << endl;
      
      p1 = p1->getNextLink();
    }
  

  // Add a node at the begining of the List 
  cout << endl;
  cout << "Adding a node at the head of the List ... .." << endl;
  DLIntNodePtr head=NULL;           // Empty node
  head = new DLIntNode(5,NULL,p);   // Assign address of p to head 
  p->setPrevLink(head);             // Change the prev pointer of p

  // Forward traversing the new List
  cout << "Forward traversing the nodes of the List ... " << endl;
  while ( head != NULL )
    { 
      cout << head->getPrevLink() << " " 
	   << head->getData()     << " "
	   << head->getNextLink() << endl;

      head = head->getNextLink();
    }
  cout << endl;


  // Backward Traversing the List
  cout << "Backward traversing the nodes of the List: " << endl; 
  while ( p2->getNextLink() != NULL )
    p2 = p2->getNextLink(); 
  
  DLIntNodePtr tail = p2;  
  while ( tail != NULL )
    { 
      cout << tail->getData() << " "; 
      tail = tail->getPrevLink();
    } 
 

  cout << endl;
  return 0;
}
