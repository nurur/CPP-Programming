// Example 17.31, 17.32, 17.33
// Self-Test exercise 24
// Iterator Class
// Singly Linked List using Iterator Class


#include <cstdlib>
#include <cstddef>
#include <iostream>
using namespace std;


//Node Class
template<class T>
class Node
{
public:
  Node() : data(0), link(NULL) { }
  Node(const T& theData, Node<T>* theLink)
    : data(theData), link(theLink) { }

  Node(const Node<T>& copy) 
    : data(copy.data)
  { link = (copy.link ? new Node<T>(*copy.link) : NULL); }
 
  ~Node(){};
  
  const T   getData() const { return data; }
  Node<T>*  getLink() const { return link; }

  void setData(const T& setData) { data = setData; }
  void setLink(Node<T>* setLink) { link = setLink; }

private:
       T   data;
  Node<T>* link;
};



//Iterator Class
template<class T>
class ListIterator
{
public:
  ListIterator() : current(NULL) { } 
  ListIterator(Node<T>* initial) : current(initial) { } 
  const T operator *() const { return current->getData(); } 

  ListIterator operator++()      //Prefix form
  {
    current = current->getLink();
    return *this;
  }

  ListIterator operator++(int)   //Postfix form
  {
    ListIterator startVersion(current);
    current = current->getLink();
    return startVersion;
  }

  bool operator ==(const ListIterator& rightSide) const 
  { return current == rightSide.current; }
  bool operator !=(const ListIterator& rightSide) const 
  { return current != rightSide.current; }

private:
 Node<T>* current;
};



//**************************************************************************
template<class T>
class Queue
{
public:
  typedef ListIterator<T> iterator;

  Queue();
  Queue(const Queue<T>& aQueue);
  Queue<T>& operator =(const Queue<T>& rightSide);

  virtual ~Queue();

  void add(T item);
  T remove();
  bool inQueue(Queue<T> q, T target);
  bool isEmpty() const;

  iterator begin() const { return  iterator(front); }
  iterator   end() const { return iterator(); }

private:
  Node<T>* front;
  Node<T>* back;
};


//Default constructor 
template<class T>
Queue<T> :: Queue() : front(NULL), back(NULL) { }


//Copy Constructor 
template<class T>
Queue<T> :: Queue(const Queue<T>& aQueue)
{
  if ( aQueue.isEmpty() )
    front = back = NULL;
  else
    {
      Node<T>* tmp = aQueue.front;
      //tmp moves through the node from front to back of aQueue

      back = new Node<T>(tmp->getData(), NULL);
      front = back;
  
      tmp = tmp->getLink();
      //tmp now points to second node or NULL if there is no second node

      while(tmp != NULL)
	{
	  back->setLink( new Node<T>(tmp->getData(), NULL) );
	  back = back->getLink();
	  tmp  = tmp->getLink();
	}
      //back->link == NULL
    }
}


//Copy Assignment operator 
template<class T>
Queue<T>&  Queue<T> :: operator=(const Queue<T>& rightSide)
{
  if (front == rightSide.front)  //if two queues are the same
    return *this;
  else
    {
      T next;
      while (!isEmpty()) next = remove();
    }


  if (rightSide.isEmpty())       //if two queues are not the same
    {
      front = back = NULL;
      return *this;
    }
  else
    {
      Node<T>* tmp = rightSide.front;
      //tmp moves through the node from front back of rightSide
 
      back = new Node<T>(tmp->getData(), NULL);
      front = back;
      //first node created and filled with data
      //new nodes are now added AFTER this first node

      tmp = tmp->getLink();
     //tmp now points to second node or NULL if there is no second node

      while (tmp != NULL)
	{
	  back->setLink( new Node<T>(tmp->getData(), NULL) );
	  back = back->getLink();
	  tmp  = tmp->getLink(); 
	}
      //back->link == NULL

      return *this;
    }
}


//Destructor 
template<class T>
Queue<T> :: ~Queue()
{
  T next;
  while ( !isEmpty() ) next = remove(); //remove calls delete
}


//Member function 
template<class T>
void Queue<T> :: add(T item)
{
  if ( isEmpty() )                             //if the node is empty then  
    front = back = new Node<T>(item, NULL);    //front and back both points 
                                               //to the same node 
  else
    {                                          //after the first entry
      back->setLink( new Node<T>(item, NULL) );//'back' now points to the new 
                                               //entry but so is 'front'! since
                                               //they are created as the same!

      back = back->getLink();                  //but then 'back' points to 
                                               //the address of the new entry
                                               //which is always 'NULL'
    }
}


//Member function 
template<class T>
T Queue<T> :: remove()
{
  if ( isEmpty() ) 
    { 
      cout << "Error: Removing an item from an empty Queue.\n";
      exit(1);
    }

  T result = front->getData();

  Node<T>* discard;
  discard = front;
  front   = front->getLink();

  if (front == NULL) back = NULL;
  delete discard;

  return result;
}


//Member function 
template<class T>
bool Queue<T> :: inQueue(Queue<T> q, T target)
{
  Queue<T> :: iterator i;    
  for (i=q.begin(); i != q.end(), *i != target; i++)
    return true; 
  //return ( i != q.end() );
  
  /*
    i=q.begin(); 
    while (i != q.end() && *i != target)
    { 
    i++;
    return true; 
    //return ( i != q.end() );
    }
  */
}

//Member function 
template<class T>
bool Queue<T> :: isEmpty() const
{ 
  //return (back == NULL) or return (front == NULL) will also work
  return (front == NULL && back == NULL); 
}
//**************************************************************************





int main()
{
  char next, ans, targetChar;
  Queue<char> q1, q2;

  do
    {
      cout << "Enter a line of text:\n";
      cin.get(next);
      while (next != '\n')
	{
	  q1.add(next);
	  q2.add(next);
	  cin.get(next);
	}

      cout << "You entered:\n";
      Queue<char> :: iterator i;
      for (i=q1.begin(); i != q1.end(); i++)
	cout << *i;
      cout << endl;
 

      //use member function 'inQueue'
      cout << "Type any character that you want to check in the Queue: ";
      cin >> targetChar;
      cout << "Going through the elements of the Queue : \n";
      cout << endl;

      //q2.inQueue(q2, targetChar); 

      /*
      int count = 0;
      //while ( !q2.isEmpty() )
      {
      */
      int count=0;
      for (i=q2.begin(); i != q2.end(); i++)
	{
	  if ( q2.inQueue(q2, targetChar) )
	    {
	      cout << "Character matched! The character is: " 
		   << targetChar << endl;
	      count = count + 1;
	    }
	  else 
	    cout << "Sorry, no match found!" << endl;
	}
      cout << "Total number of match is : " << count << endl;
      cout << endl;
      
      

      cout << "Again? (y/n): ";
      cin >> ans;
      cin.ignore(10000, '\n');
    } while (ans != 'n' && ans != 'N');


  return 0;
} 












