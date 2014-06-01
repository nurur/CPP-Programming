// Self-Test Exercise 17.1, 17.2, 17.3
// Nodes and Linked List


#include <iostream>
using namespace std;


struct Node
{
  int count;
  string item;
  Node* link;
};


struct Box
{
  int number;
  string name;
  Box* next;
};


typedef Box* BoxPtr;
typedef Node* NodePtr;



int main()
{
  BoxPtr head  = new Box;
  head->name   = "Sally";
  head->number = 18;
  head->next   = NULL;

  cout << (*head).name   << endl;
  cout << (*head).number << endl;
  cout << (*head).next   << endl;
  cout << endl;

  cout << head->name   << endl;
  cout << head->number << endl;
  cout << head->next   << endl;
  cout << endl;


  NodePtr headLN = new Node;
  headLN->item = "Wilbur's brother is Orville";
  cout << headLN->item   << endl;

  return 0;
}
