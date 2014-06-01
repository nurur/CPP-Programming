// ChList Class

#include <iostream>
using namespace std;



#ifndef CHLIST_HPP
#define CHLIST_HPP


class chList
{
public:
  chList();
  chList(const chList& c);
  ~chList();
  chList& operator=(const chList& c);
  
  int Addtofront(const char& c);
  int RmvHead(char& c);
  void Clear();
  int IsEmpty();
  int IsFull();
  
protected:
  int out_of_memory;
  chNode* head;
  void copy(const chList& c);
};



void chList :: Copy(const chList& s)
{
  clear();

  ChNode* sn = s.head;

  if (sn)
    {
      ChNode* tn = new ChNode;
      head = tn;
      
      while (sn && tn)
	{
	  tn->data = sn->data;
	  sn = sn->next;
	  if (sn)
	    {
	      tn->next = new ChNode;
	      tn = tn->next;
	    }
	}
      
      if (!tn) out_of_memory = 1;
    }
}



chList :: chList(const chList& c)
// Copy constructor 
{
  head = 0;
  out_of_memory = 0;
  Copy(c);
}


chList :: ~chList()
// Destructor. 
// It removes all nodes from the list  
{
  Clear();
}


chList& chList :: operator=(const chList& c)
// Assignment copy  operator.
// Clears contents of the existing list
// Makes a copy of list c
{
  Copy(c);
  return *this;
}



int chList :: AddtoFront(const char& c)
// Adds node to the front of the list, making a new head. 
// Returns 1 if successful.
{
  ChNode* t = new ChNode(c, head);
  if (t)
    {
      head = t;
      return 1;
    }
  else
    {
      out_of_memory = 1;
      return 0;
    }
}

int chList :: RmvHead(char& c)
{
  if (head)
    {
      c = head->data;
      ChNode* p = head;
      head = head->next;
      delete p;
      out_of_memory = 0;
      return 1;
    }
  else return 0;
}

void chList :: Clear()
// Removes all nodes from the list 
{
  char dmy;
  int r;
  do
    {
      r = RmvHead(dmy);
    } while (r);
}


#endif
