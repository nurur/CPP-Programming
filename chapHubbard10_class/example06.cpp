// EXAMPLE 10.12, 10.13
// Singly Linked List 
// Pointer to Objects of Node Class


#include <iostream>
using namespace std;


class Node
{
public :
  Node(){};
  Node(int d, Node* q) : data(d), next(q) { }

  int  data;      // stored data value in a node
  Node* next;     // reference to the next node
};



int main ()
{
  Node* a = new Node(22,0);
  cout << (*a).data << ", " << (*a).next << endl; 


  int count, value;
  Node* p;       // pointer traverse the linked list 
  Node* q = 0;   // pointer only connects new node to previous node
 
  count = 0;
  while (count <= 5)
    {
      cin >> value;
      p = new Node(value,q);
      q = p;
      
      ++count;
      cout << p->data << ", " << &(p->data) << ", " << p->next << endl;
      cout << q->data << ", " << &(q->data) << ", " << q->next << endl;
    }
  cout << endl;

  
  /*
    for ( ; p != NULL; p = p->next)  
    cout << p->data << ", " << p->next << " -> ";
    cout << "*\n";
  */

  while (p != NULL )
    {cout << p->data << ", " << p->next << " -> ";
      p = p->next;
    }


  cout << endl;
  return 0;
}  
  
