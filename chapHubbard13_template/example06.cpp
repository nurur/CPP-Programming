// Example:
// Template Specialization

/*
  If we want to define a different implementation for a template when a 
  specific type is passed as template parameter, we can declare a 
  specialization of that template.

  For example, let's suppose that we have a very simple class called 
  myContainer that can store one element of any type and that it has just 
  one member function called increase, which increases its value. But we 
  find that when it stores an element of type char it would be more 
  convenient to have a completely different implementation with a function 
  member uppercase, so we decide to declare a class template specialization 
  for that type:

  When we declare specializations for a template class, we must also define 
  all its members, even those exactly equal to the generic template class, 
  because there is no "inheritance" of members from the generic template to 
  the specialization.
*/


#include <iostream>
using namespace std;


// generic class template:
template <class T>
class myContainer 
{
public:
  myContainer(){};
  myContainer(T arg) : element(arg) {}
  T increase() { return ++element; }
  
private:
  T element;
};

// class template specialization:
template<>
class myContainer <char> 
{
public:
  myContainer(){};
  myContainer(char arg) : element(arg) { }
  char uppercase()
  {
    if ((element >= 'a') && (element <= 'z'))
      element += 'A' - 'a';
    return element;
  }
  
private:
  char element;
};



int main () 
{
   myContainer<int>  myint   (7);
  myContainer<char> mychar ('j');

  cout <<   myint.increase() << endl;
  cout << mychar.uppercase() << endl;

  cout << endl;
  return 0;
}

