// EXAMPLE : 10.12, 10.13
// Singly Linked List 
// Alternative method of coding (Example06.cpp)


#include <iostream>
using namespace std;


struct Node
{
public :
  int  data;      // stored data in a node,      "data field"
  Node* next;     // reference to the next node, "address" or "link" field
};



int main ()
{
  float i,j,k;
  i = j = k = 3.1415;
  cout << i << " " << j<< " "<< k << endl;

  int count, value;
  Node* p;
  Node* q = 0;   // pointer that connects new node to previous node
  

  count = 0;
  while (count <= 5)
    {
      cin >> value;

      p    = new Node;      
      p->data = value;        // store data
      p->next = q;            // store adress of q
      
      q = p;                  // q points to node p
                              // transfer address of p to q

      ++count;      
      cout << p->data << ", " << &(p->data) << ", " << p->next << endl;
      cout << q->data << ", " << &(q->data) << ", " << q->next << endl;
    }
  cout << endl; 


  Node* tmp1;
  Node* tmp2;
 
  while ( p != NULL )
    {cout << p->data << ", " << p->next << " -> ";

      tmp1 = new Node;
      tmp1 = p;
      //tmp1->data = p->data;
      //tmp1->next = p->next;
      //cout << "tmp1:" << tmp1->data << ", " << tmp1->next << " -> ";

      p = p->next;
    }
  cout << endl; 
  cout << endl;
  

  // inserting node at the end of the list
  cout << "Inserting Node at the End :" << endl; 
  cout << endl;

  tmp2 = new Node;

  cout<< "Enter a value for the new node : "; cin >> value;
  tmp2->data = value;
  tmp2->next = NULL;
  tmp1->next = tmp2;

  while ( tmp1 != NULL )
    {cout << tmp1->data << ", " << tmp1->next << " -> ";
      tmp1 = tmp1->next;
    }


  cout << endl;
  return 0;
}  
