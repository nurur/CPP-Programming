// Example 17.14, 17.15
// Generic Singly Linked List using Template
// Stack Class
// Stack Class is a Friend Class of Node Class


#include <cstdlib>
#include <cstddef>
#include <iostream>
using namespace std;



//Forward Delecaration 
template<class T>
class Stack;


//Node Class
template<class T>
class Node
{
  friend class Stack<T>;
  
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
  
private:
       T   data;
  Node<T>* link;
};



//**************************************************************************
template<class T>
class Stack
{
public:
  Stack();
  Stack(const Stack<T>& aStack);
  Stack<T>& operator =(const Stack<T>& rightSide); 
 
  virtual ~Stack();

  void push(T stackFrame);
  T pop();
  bool isEmpty() const;

private:
  Node<T>* top;
};


//Default constructor 
template<class T>
Stack<T> :: Stack() : top(NULL) { }


//Copy Constructor 
template<class T>
Stack<T> :: Stack(const Stack<T>& aStack)
{ 
  if ( aStack.isEmpty() )
    top = NULL;

  else
    {
      Node<T>* tmp = aStack.top;
      //tmp moves through the node from top to bottom of aStack

      Node<T>* end;
      //points to the topEnd of left-side stack
      end = new Node<T>(tmp->data, NULL);
      top = end;
  
      tmp = tmp->link;
      //tmp now points to second node or NULL if there is no second node

      while(tmp != NULL)
	{
	  end->link = new Node<T>(tmp->data, NULL);
	  end = end->link;
	  tmp = tmp->link;
	}
      //end->link == NULL
    }
}


//Copy Assignment operator 
template<class T>
Stack<T>&  Stack<T> :: operator=(const Stack<T>& rightSide)
{
  if (top == rightSide.top)     //if two stacks are the same
    return *this;
  else
    {
      T next;
      while ( !isEmpty() ) next = pop(); 
    }


  if ( rightSide.isEmpty() )    //if rightSide is an empty stack
    {
      top = NULL;               //make the leftSide empty as well 
      return *this;
    }
  else                          //if rightSide is not an empty stack
    {                           //copy the stack
      Node<T>* tmp = rightSide.top;
      //tmp moves through the node from top to bottom of rightSide
 
      Node<T>* end;
      //points to the topEnd of left-side stack
      end = new Node<T>(tmp->data, NULL);
      top = end;
      //first node created and filled with data
      //new nodes are now added AFTER this first node

      tmp = tmp->link;
     //tmp now points to second node or NULL if there is no second node

      while (tmp != NULL)
	{
	  end->link = new Node<T>(tmp->data, NULL);
	  end = end->link;
	  tmp = tmp->link; 
	}
      //end->link == NULL

      return *this;
    }
}


//Destructor 
template<class T>
Stack<T> :: ~Stack()
{
  T next;
  while ( !isEmpty() ) next = pop(); //pop calls delete
}


//Member function 
template<class T>
void Stack<T> :: push(T stackFrame)
{
  //top is NULL for the first entry
  //becuase it goes at the bottom of the stack
  //input: Nurur
  //r -> u -> r -> u -> N (NULL)
  top = new Node<T>(stackFrame, top);
}

//Member function 
template<class T>
T Stack<T> :: pop()
{
  if ( isEmpty() ) 
    { 
      cout << "Error: Removing an item from an empty Stack.\n";
      exit(1);
    }
  
  T result = top->data;
  
  Node<T>* discard;
  discard = top;
  top = top->link;
  
  delete discard;

  return result;
}


//Member function 
template<class T>
bool Stack<T> :: isEmpty() const
{ return (top == NULL); }
//**************************************************************************




int main()
{  
  char next, ans;

  do
    {
      Stack<char> s;
      cout << "Enter a line of text:\n";
      cin.get(next);
      while (next != '\n')
	{
	  s.push(next);
	  cin.get(next);
	}

      cout << "Writing backward of what you entered:\n";
      while ( !s.isEmpty() )
	cout << s.pop();
      cout << endl;
      

      cout << "Again? (y/n): ";
      cin >> ans;
      cin.ignore(10000, '\n');
    } while (ans != 'n' && ans != 'N');



  return 0;
} 
