// Example 17.3, 17.4
// Single Linked List
// Adding node at the begining of a List
// Traversing a List 
// Adding node at the end of a List


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

private:
  int      data;
  SLIntNode* link;
};
typedef SLIntNode* SLIntNodePtr;




int main()
{
  // Inserting Node at the Head of a List
  // method 1:
  SLIntNodePtr h1, h2, h3;
  h1 = new SLIntNode(3,0);
  cout << h1->getData() << "  " << h1->getLink() << endl;

  h2 = new SLIntNode (15,h1);
  cout << h2->getData() << "  " << h2->getLink() << endl;

  h3 = new SLIntNode(12,h2);
  cout << h3->getData() << "  " << h3->getLink() << endl;

  while ( h3 != NULL )
    {
      cout << h3->getData() << ", " << h3->getLink() << " -> ";
      h3 = h3->getLink();
    }

  cout << endl;


  // method 2
  const int SIZE = 3;
  int a[SIZE] = {3,15,12};

  // Note: p=List, q=Head
  SLIntNodePtr p;
  SLIntNodePtr q=NULL;
  for (int i=0; i<SIZE; i++) 
    { 
      p = new SLIntNode(a[i],q);
      q = p;
    }

  // Add a node at the begining of List 
  cout << endl;
  cout << "Case 1: Add a node at the head of a List: " << endl;
  SLIntNodePtr Head=NULL;          // Empty Node
  Head = new SLIntNode(8,p);
  cout << endl;

  // Case 2: Traversing a List
  cout << "Case 2: Traversing the nodes of a List: " << endl;
  while ( Head != NULL )
    { 
      cout << Head->getData() << ", " << Head->getLink() << " -> ";
      Head = Head->getLink();
    }

  /*
  while ( p != NULL )
    { cout << p->getData() << ", " << p->getLink() << " -> ";
      p = p->getLink();
    }
  */
  cout << endl;


  // Case 3: Insert Node at the Tail of a List
  cout << "Case 3: Insert a node at the tail of a List: " << endl;
  SLIntNodePtr tmp;               // Copy Head to tmp  
  tmp = Head;

  while(tmp->getLink() != NULL)   // Go to the last node
    tmp = tmp->getLink();         // Transfer address of 'tmp->next' to 'tmp'
  
  SLIntNodePtr Tail;              // New Last Node
  Tail = new SLIntNode(2,0);
  //Head->getLink() = Tail;
  cout << endl; 


  cout << endl;
  return 0;
}
