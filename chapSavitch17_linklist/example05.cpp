// Example 17.7
// Single Linked List
// Deleting a node to anywhere in the List (first, middle, or end)


#include <cstdlib>
#include <iostream>
using namespace std;


class SLIntNode
{
public:
  SLIntNode(){};
  SLIntNode(int theData, SLIntNode* theLink) 
  : data(theData), link(theLink) { }

  //COPY CONSTRUCTOR 
  SLIntNode(const SLIntNode& copy) 
  : data(copy.data)
  { link = (copy.link ? new SLIntNode(*copy.link) : NULL); }

  //DESTRUCTOR
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

private:
  int      data;
  SLIntNode* link;
};

typedef SLIntNode* SLIntNodePtr;



int main()
{
  const int SIZE = 6;
  int a[SIZE] = {18,15,11,9,3,2};
 
  // Note: p=List, q=Head
  SLIntNodePtr p;
  SLIntNodePtr q=NULL;
  for (int i=0; i < SIZE; i++) 
    { 
      p = new SLIntNode(a[i],q);
      q = p;
    }

  cout << "The existing list is ... ... \n";
  for (int i=SIZE-1; i>=0; i--)
    cout << a[i] << " ";
  cout << endl;

  int nodeNumber;
  cout << "Enter the number of the node that will be \n" 
       << "deleted (starting from 0) : "; 
  cin >> nodeNumber;
  cout << endl;

  // Create temporary nodes immediately before and after 
  // The node that will be deleted 
  SLIntNodePtr before, discard;             
  // Assign the head of the existing List to before 
  before = p;                      

  // Find the node before the one that will be deleted
  if (nodeNumber == 0)
    {  
      before = before->getLink();
           p = before;
    }

  if (nodeNumber >= 1)
    {
      //for loop for nodeNumber > 1
      for (int i=0; i<nodeNumber-1; i++)
	{ 
	  before = before->getLink();  
	  
	  if( before->getLink() == NULL )
	    { 
	      cout << "Node " << nodeNumber 
		   << " does not exist!\n" 
		   << "Aborting ... ...\n";
	      exit(1);
	    }
	}//for loop ends
      
      discard = before->getLink();   
      before->setLink(discard->getLink());         
    }
  

  // Print the new List 
  cout << "The revised list is ... ... \n";
  while ( p != NULL )
    { 
      cout << p->getData() << " ";
      p = p->getLink();
    }

  // Release memory back to the freestore
  for (int i=0; i<SIZE; i++) 
    { delete p; }
  // Make p and q as NULL pointers
  p=0; q=0;
  
  cout << endl;
  return 0;
}
