// Example 
// Double Linked List
// Sorting a List 


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
  cout << endl << endl;


  DLIntNodePtr tmp1, tmp2;
  int tmp = 0;    // store temporary data value
  
  for (tmp1=p; tmp1!=NULL; tmp1=tmp1->getNextLink())
    {
      for (tmp2=tmp1->getNextLink(); tmp2!=NULL; tmp2=tmp2->getNextLink())
	{
	  if (tmp1->getData() > tmp2->getData())
	      {
		tmp = tmp1->getData();
		tmp1->setData( tmp2->getData() );
		tmp2->setData( tmp );
            }
	}
    }

  cout << "The sorted list is ... ... . \n";
  for (tmp1=p; tmp1!=NULL; tmp1=tmp1->getNextLink())
    cout << tmp1->getData()<< " "; 
  cout << endl;
  
  return 0;
}
