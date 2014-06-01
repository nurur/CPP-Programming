// Example 17.6
// Single Linked List
// Adding a node to anywhere in the List (first or middle)


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

  void insert(SLIntNode* afterMe, int theData);

private:
  int      data;
  SLIntNode* link;
};


void SLIntNode :: insert(SLIntNode* afterMe, int theData)
{ 
  SLIntNode* newLink =  afterMe->getLink();
  afterMe->setLink( new SLIntNode(theData, newLink) ); 
}

typedef SLIntNode* SLIntNodePtr;




int main()
{
  const int SIZE = 6;
  int a[SIZE] = {18,15,11,9,3,2};

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
  cout << endl << endl;


  int nodeNumber, nodeValue;
  cout << "Enter the number of the node where the new node \n"
       << "will be inserted (starting from 0) : "; 
  cin >> nodeNumber;
   cout << "Enter the number that will be inserted : "; 
  cin >> nodeValue;

  // Create a temporary newNode
  SLIntNodePtr newNode;             
  // Assign the head of the existing List to the newNode 
  newNode = p;                      
  
  // Find the node after which the newNode will be inserted
  if (nodeNumber == 0)
    { 
      p = new SLIntNode(nodeValue,p);
    }

  if (nodeNumber >= 1)
    {
      //for loop for nodeNumber > 1
      for (int i=1; i<nodeNumber; i++)
	{ 
	  newNode = newNode->getLink(); 
 
	  if( newNode->getLink() == NULL )
	    { 
	      cout << "Node " << nodeNumber 
		   << " does not exist!\n" 
		   << "Aborting ... ...\n";
	      exit(1);
	    }
	}//for loop ends

      newNode->insert(newNode,nodeValue);         
    }
  
  // Print the new List 
  while ( p != NULL )
    { cout << p->getData() << " ";
      p = p->getLink();
    }


  cout << endl;
  return 0;
}
