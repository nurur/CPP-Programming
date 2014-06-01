// Example 17.14, 17.15
// Generic Singly Linked List using Template

#include <cstddef>
#include <iostream>
using namespace std;


template<class T>
class Node
{
public:
  Node() : data(0), link(NULL) { }
  Node(const T& theData, Node<T>* theLink)
    : data(theData), link(theLink) { }

  Node(const Node& copy) 
    : data(copy.data)
  { link = (copy.link ? new Node(*copy.link) : NULL); }
 
  //~Node(){};
  
  const T   getData() const { return data; }
  Node<T>*  getLink() const { return link; }

  void setData(const T& setData) { data = setData; }
  void setLink(Node<T>* setLink) { link = setLink; }

private:
       T   data;
  Node<T>* link;
};


template<class T>
void insertFirstNode(Node<T>*& head, const T& theData)
{
  head = new Node<T>(theData, head);
}


template<class T>
void insertAnyNode(Node<T>* afterMe, const T& theData)
{
  Node<T>* newLink =  afterMe->getLink();
  afterMe->setLink( new Node<T>(theData, newLink) );
}


template<class T>
void deleteFirstNode(Node<T>*& head)
{
  Node<T>* discard = head;
  head = head->getLink();
  delete discard;
}


template<class T>
void deleteAnyNode(Node<T>* before)
{
  Node<T>* discard = before;
  discard = before->getLink();
  before->setLink( discard ->getLink() );
  delete discard;
}


template<class T>
Node<T>* searchNode(Node<T>* head, const T& target)
{
  Node<T>* here = head;
  
  if (here == NULL) return NULL;
  
  while (here->getData() != target && here->getLink() != NULL)
    here = here->getLink();
  
  if (here->getData() == target)
    return here;
  else
    return NULL;
}





int main()
{  
  const int SIZE = 6;
  int a[SIZE] = {18,15,11,9,3,2};

  // Note: p=List, q=Head
  Node<int> p;
  Node<int> q=NULL;
  for (int i=0; i<SIZE; i++) 
    { 
      p = new Node<int>(a[i],q);
      q = p;
    }

  cout << "The existing list is ... ... \n";
  for (int i=SIZE-1; i>=0; i--)
    cout << a[i] << " ";
  cout << endl << endl;


  return 0;
}
