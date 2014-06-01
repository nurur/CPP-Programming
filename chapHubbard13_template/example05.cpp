// Example: 13.8
// Iterator Class 

#include <cstdlib>
#include <cstddef>
#include <iostream>
using namespace std;



template <class T>    //forward declaration of List Class
class List;
template <class T>    //forward declaration of ListIterator Class
class ListIterator;



//ListNode Class -------------------------------------------------------------
template <class T>
class ListNode
{
  friend class List<T>;
  friend class ListIterator<T>;

public:
  ListNode(T& theData, ListNode<T>* theNext)
    : data(theData), next(theNext) { }
    
protected:
  T data;
  ListNode* next;
};



//List Class  -----------------------------------------------------------------
template <class T>
class List
{
  friend class ListIterator<T>;
  
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



//Iterator Class --------------------------------------------------------------
template <class T>
class Iterator
{
public:
  virtual void reset() =0;               //initialize the iterator 
  virtual T operator()() =0;             //read current value
  virtual void operator=(T theData) =0;  //write current value
  virtual int operator!() =0;            //determine whether item exists
  virtual int operator++() =0;           //advance to next item
};


//Iterator Class --------------------------------------------------------------
template <class T>
class ListIterator : public Iterator<T>
{
public:
  ListIterator(List<T>& l) : list(l) { reset(); } 

  virtual void reset() { previous = NULL; current = list.first; }
  virtual T operator()() { return current->data; }
  virtual void operator=(T theData) {current->data = theData; }
  virtual int operator!();
  virtual int operator++();
  
  void insert (T theData);
  void preInsert(T theData);
  void remove();

protected:
 ListNode<T>* current;
 ListNode<T>* previous;
 List<T>& list;
};



template <class T>
int ListIterator<T> :: operator! ()
{
  if (current == NULL)
    if (previous == NULL) current = list.first;
    else current=previous->next;
  return (current != NULL);
}


template <class T>
int ListIterator<T> :: operator++ ()
{
  if (current == NULL)
    if (previous == NULL) current = list.first;
    else current=previous->next;
  else
    {
      previous = current;
      current  = current->next; 
    }
  return (current != NULL);
}


template <class T>
void ListIterator<T> :: insert(T theData)
{
  ListNode<T>* p = new ListNode<T>(theData, NULL);
  
  if ( list.isEmpty() ) list.first = p;
  else
    {
      p->next = current->next;
      current->next = p;
    }
}


template <class T>
void ListIterator<T> :: preInsert(T theData)
{
  ListNode<T>* p = new ListNode<T>(theData, current);
  
  if ( current == list.first ) list.first = previous = p;
  else previous->next = p;
}


template <class T>
void ListIterator<T> :: remove()
{
  if ( current == list.first ) list.first = current->next;
  else previous->next = current->next;

  delete current;
  current=0;
}





int main()
{
  
  List<string> friendList;
  ListIterator<string> it(friendList);

 
  //Insert
  it.insert("Bowen, Van");
  ++it;
  it.insert("Dixon, Tom");
  ++it;
  it.insert("Mason, Joe");
  ++it;
  it.insert("White, Ann");
  ++it;

  //Print
  friendList.print();
  cout << endl;
  
  it.reset();
  ++it;
  it = "Davis, Jim";
  ++it;
  it.remove();
  friendList.print();
  cout << endl;


  if (!it) it.preInsert("Morse, Sam");
  friendList.print();
  cout << endl;

  for (it.reset(); !it; ++it)
    it = "[" + it() + "]";

  friendList.print();
  cout << endl;

  return 0;
}
