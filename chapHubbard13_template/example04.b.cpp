// Example: 13.7
// Class Template: Linked List
// Eliminating the 'newNode()' function from the List Class


#include <iostream>
using namespace std;


template <class T>    //forward declaration of List Class
class List;


//ListNode Class
template <class T>
class ListNode
{
  friend class List<T>;

public:
  ListNode(T& theData, ListNode<T>* theNext)
    : data(theData), next(theNext) { }
    
protected:
  T data;
  ListNode* next;
};


//List Class
template <class T>
class List
{
public:
  List();
 ~List();

  void insert (T theData);
  int  remove (T& theData);
  bool isEmpty() { return (first == 0); } 
  void print();

protected:
  ListNode<T>* first;
};


template <class T>
List<T> :: List()
{ 
 first = NULL; 
};


template <class T>
List<T> :: ~List()
{
  /*Method 1
  ListNode<T>* current = first;
  while(current != 0)
    {
      ListNode<T>* tmp = current->next;
      delete current;
      current=tmp;
    }    
  */

  //Method 2: 'tmp' is 'current'
  ListNode<T>* current;
  ListNode<T>* tmp;
  for (tmp=first; tmp != NULL; tmp=tmp->next)
    {
      current = tmp;
      delete current;
    }
};


template <class T>
void List<T> :: insert(T theData)
{
  ListNode<T>* p = new ListNode<T> (theData, first);
  first = p;
}


template <class T>
int List<T> :: remove(T& theData)
{
  if (isEmpty()) return 0;

  theData = first->data;  //Data value returned by reference 

  ListNode<T>* tmp = first;
  first = first->next;   //Advance first pointer to remove node
  delete tmp;

  return 1;
}

template <class T>
void List<T> :: print()
{
  for (ListNode<T>* tmp=first; tmp != NULL; tmp=tmp->next)
    {
      if ( tmp->next != NULL )
      cout << tmp->data << " -> ";
      else
      cout << tmp->data;
    }
}





int main()
{
  List<string> friendList;

  //Insert
  friendList.insert("Bowen, Van");
  friendList.insert("Dixon, Tom");
  friendList.insert("Mason, Joe");
  friendList.insert("White, Ann");

  //Print
  friendList.print();
  cout << endl;

  //Remove
  string name;
  friendList.remove(name);
  cout << "Removed : " << name << endl;
 
  //Print
  friendList.print();
  cout << endl;


  return 0;
}
