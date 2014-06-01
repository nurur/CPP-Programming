// Example 17.20, 17.21
// Generic Singly Linked List using Template
// Queue Class


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
  {
    data = copy.data;
    link = (copy.link ? new Node<T>(copy.link) : NULL); 
  }

  ~Node(){};
  
  const T   getData() const { return data; }
  Node<T>*  getLink() const { return link; }

  void setData(const T& setData) { data = setData; }
  void setLink(Node<T>* setLink) { link = setLink; }

private:
       T   data;
  Node<T>* link;
};




//**************************************************************************
template<class T>
class Queue
{
public:
  Queue();
  Queue(const Queue<T>& aQueue);
  Queue<T>& operator =(const Queue<T>& rightSide);

  virtual ~Queue();

  void add(T item);
  T remove();
  bool inQueue(Queue<T> q, T item);  
  bool isEmpty() const;

private:
  Node<T>* front;   //points to the head node of the linked list
  Node<T>* back;    //points to the node at the other end of the linked list
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
  if (front == rightSide.front)   //if two queues are same
    return *this;
  else
    {
      T next;
      while (!isEmpty()) next = remove();
    }


  if ( rightSide.isEmpty() )     //if rightSide is an empty queue
    {
      front = back = NULL;       //make the leftSide empty as well 
      return *this;
    }
  else                           //if rightSide is not an empty stack
    {                            //copy the queue
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
  if ( isEmpty() )                           //if the queue is empty then  
    front = back = new Node<T>(item, NULL);  //creates the first node where 
                                             //'front' and 'back' both points
                                             //to the same node 
  else
    {                                          //after the first node created
      back->setLink( new Node<T>(item, NULL) );//both 'front and ''back' now 
                                               //points to the new node

      back = back->getLink();  //'back' is assigned the address of the new node 
                               //which is always 'NULL'
                               //'front' keeps pointing to the second node 
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
  //if front node is the last node that is to be removed
  //then 'back' node must be assigned to NULL

  delete discard;

  return result;
}


//Member function 
template<class T>
bool Queue<T> :: inQueue(Queue<T> q, T target)
{
  T result = front->getData(); 

  front  = front->getLink();  
  if (front == NULL) back = NULL;
  //if front node goes up to the last node to be searched 
  //then 'back' node must be assigned to NULL

  return (result == target);
}


//Member function 
template<class T>
bool Queue<T> :: isEmpty() const
{ 
  //return (front == NULL) or return (back == NULL) will also work 
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


      //use member function 'inQueue'
      cout << "Type any character that you want to check in the Queue: ";
      cin >> targetChar;
      cout << "Going through the elements of the Queue : \n";
      cout << endl;

      int count = 0;
      while ( !q1.isEmpty() )
	{
	  if ( q1.inQueue(q1, targetChar) )
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
      

      //use member function 'remove'
      cout << "You entered:\n";
      while ( !q2.isEmpty() )
	cout << q2.remove();
      cout << endl;
      

      cout << "Again? (y/n): ";
      cin >> ans;
      cin.ignore(10000, '\n');
    } while (ans != 'n' && ans != 'N');


  return 0;
} 












