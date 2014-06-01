// Example 15.7 
// Pointers and Virtual Functions 
// Slicing Problem  and the Trick to get around it


#include <iostream>
using namespace std;


class Pet
{
public:
  string name;
 virtual void print() const;
};

void Pet :: print() const
{ cout << name << endl; }


class Dog : public Pet
{
public:
  string breed;
  virtual void print() const;
};

void Dog :: print() const 
{ 
cout << name  << endl; 
cout << breed << endl; 
}



int main()
{
  Pet vpet;
  Dog vdog;
  vdog.name  = "Tiny";
  vdog.breed = "Great Dane";

  vpet = vdog;
  cout << "The slicing problem:\n";
  vpet.print();
  cout << endl;


  cout << "The slicing problem defeated:\n";
  Pet *ppet;
  Dog *pdog;
  ppet = new Pet;
  pdog = new Dog;

  pdog->name  = "Tiny";
  pdog->breed = "Great Dane";

  ppet = pdog;
  ppet->print();
  pdog->print();

  
  delete pdog; 
  pdog = 0; 
  ppet = 0;

  return 0;
}
