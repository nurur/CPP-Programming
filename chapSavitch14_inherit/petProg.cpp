// Problem   : 14.10
// Inheritance 
// Driver Function: Base Class Pet


#include "Pet.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;



int main()
{
  Dog x;
  x.setName("Lerothodi");
  x.setAge(5);
  x.setWeight(60);
  x.setBreed("German Shepherd");

  cout << "Name    : " << x.getName()     << endl;
  cout << "Age     : " << x.getAge()      << " years." << endl;;
  cout << "Weight  : " << x.getWeight()   << " lb."    << endl;
  cout << "Breed   : " << x.getBreed()    << endl;
  cout << "Lifespan: " << x.getLifespan() << endl;
  cout << endl;


  Pet y;
  y.setName("Leeuw");
  y.setAge(7);
  y.setWeight(55);

  cout << "Name    : " << y.getName()     << endl;
  cout << "Age     : " << y.getAge()      << " years." << endl;;
  cout << "Weight  : " << y.getWeight()   << " lb."    << endl;
  cout << "Lifespan: " << y.getLifespan() << endl;

  return 0;
}
