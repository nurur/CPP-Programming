// Example 
// Single Linked List
// Sorting a List 


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
  const int SIZE = 10;
  int a[SIZE] = {1,18,7,15,5,11,9,3,2,23};

  SLIntNodePtr p, q=0;
  for (int i=0; i<SIZE; i++) 
    { 
      p = new SLIntNode(a[i],q);
      q = p;
    }

  cout << "The existing list is ... ... \n";
  for (int i=SIZE-1; i>=0; i--)
    cout << a[i] << " ";
  cout << endl << endl;



  SLIntNodePtr tmp1, tmp2;
  int tmp = 0;    // store temporary data value
  
  for (tmp1 = p; tmp1 != NULL; tmp1 = tmp1->getLink())
    {
      for (tmp2 = tmp1->getLink(); tmp2 != NULL; tmp2 = tmp2->getLink())
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
  for (tmp1=p; tmp1 != NULL; tmp1 = tmp1->getLink())
    cout << tmp1->getData() << " ";
  /* 
     tmp1 = p;
     while (tmp1 != NULL) 
     {
     cout << tmp1->getData() << " ";
     tmp1 = tmp1->getLink();
     }
  */
  cout << endl;

  
  return 0;
}
