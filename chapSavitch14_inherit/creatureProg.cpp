// Problem     : 14.9
// Inheritance 
// Driver Function for Base Class Creature


#include "Creature.hpp"
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;



int main()
{
  Creature x;
  x.setStrength(7);
  x.setHitpoints(5);
  //cout << x.getDamage() << endl;

  Demon y;
  y.setStrength(5);
  y.setHitpoints(4);
  cout << y.getDamage() << endl;

  Elf z;
  z.setStrength(4);
  z.setHitpoints(5);
  cout << z.getDamage() << endl;


  return 0;
}


