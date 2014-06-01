// Self-Test Exercise 17.1, 17.2, 17.3
// Nodes and Linked List


#include <iostream>
using namespace std;



// case 1
struct Node  
{
  int count;
  string item;
  Node* link;
};

class List1
{
public:
  List1() { first = NULL; }
  List1(const List1& copy);
  List1& operator=(const List1& rightSide);
  ~List1();
  
  void print();
  
private:
  Node* first;
};



// case 2
class List2  
{
private:
struct ListNode
{
  int count; 
  string item;
  ListNode* link;
};

public:
  List2();
  List2(int theCount, string theItem, ListNode* theLink);
  List2(const List2& copy);
  List2& operator=(const List2& rightSide);
  ~List2();
  
  void print();
};

//List2 :: List2() { count = 0;  item = ""; link = NULL; } 

 



int main()
{
  return 0;
}
