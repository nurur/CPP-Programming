// ChNode Class


#include "chList.hpp"
#include <iostream>
using namespace std;




class ChNode
{
  friend ChList;

public:
  ChNode();                                // default 
  ChNode(const char& d, ChNode* n);        // auxilary 

private:
  char data;
  ChNode* next;
  ChNode(const ChNode& cn);               // copy constructor 
  ChNode &operator=(const ChNode& cn);    // assignment copy constructor 
};


ChNode :: ChNode()
// Default constructor 
{ 
  data = 0;
  next = 0;
}

ChNode :: ChNode(const char& d, ChNode* n)
// Auxilary constructor
{ 
  data = d;
  next = n;
}

ChNode :: ChNode(const ChNode& cn)
// Copy constructor
// Only data is copied
// The next pointer is set to zero    
{ 
  data = cn.data;
  next = cn.next;
  next = 0;
}


ChNode &ChNode :: operator=(const ChNode& cn)
// Copy Assignment operator. 
// Only data is copied
// The next pointer is set to zero  
{ 
  data = cn.data;
  next = 0;
}




int main()
{

  return 0;
}
