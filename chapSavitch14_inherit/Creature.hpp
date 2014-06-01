// Problem     : 14.9
// Inheritance 
// Base Class Creature


#ifndef CREATURE_HPP
#define CREATURE_HPP


#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


class Creature
{
public:
  Creature();
  Creature(string theSpecies, int theStrength, int theHit);
  
  // Accesor and Mutator functions 
  string getSpecies(); 
  int   getStrength();
  
  void  setStrength(int  newStrength);
  void setHitpoints(int newHitpoints);
    
  int getDamage();

private:
  string species;   // Name of the creature
  int strength;     // How much damage we can inflict 
  int hitpoints;    // How much damage we can sustain = Endurance 

};

Creature :: Creature()
{ species = " ", strength = 0; hitpoints = 0; }

Creature :: Creature(string theSpecies, int theStrength, int theHit)
{ species = theSpecies; strength = theStrength; hitpoints = theHit; }

void Creature :: setStrength(int newStrength)
{ strength  = newStrength; } 
void Creature :: setHitpoints(int newHitpoints)
{ hitpoints = newHitpoints; }

string Creature :: getSpecies()
{ return species; } 
int Creature :: getStrength()
{ return strength; } 


int Creature :: getDamage()
// All creatures inflict the basic damage
// which is a random number up to their strength 
{   
  int damage;
  damage = ( rand() % getStrength() ) + 1;
  cout << "Basic damage by all creatures: " << damage << endl;
  return damage;
}




// ************************************************************************
class Demon : public Creature
{
public:
  Demon();
  Demon(string theSpecies, int theStrength, int theHit);

  int getDamage();
};
Demon :: Demon() : Creature() { }

Demon :: Demon(string theSpecies, int theStrength, int theHit)
  : Creature(theSpecies, theStrength, theHit) { }

int Demon :: getDamage()
{
  int damage = Creature::getDamage();  // Basic damage inflict
  if ( (rand() % 100) < 5)             // 5% chance to inflict      
    {                                  // additional 50 damage points 
      damage  = damage + 50;
      cout << " Demon attack inflicts " << damage 
	   << " additional damage points! " << endl;
    }
  return damage;
}


// ************************************************************************
class Elf : public Creature
{
public:
  Elf();
  Elf(string theSpecies, int theStrength, int theHit);
  
  int getDamage();
};

Elf :: Elf() : Creature() { }

Elf :: Elf(string theSpecies, int theStrength, int theHit)
  : Creature(theSpecies, theStrength, theHit) { }

int Elf :: getDamage()
{
  int damage = Creature::getDamage();    // Basic damage inflict
  if ( (rand() % 10) == 0 )              // 10% chance to inflict      
    {                                    // nagical damage 
      cout << "Elves inflicts magical attack " << damage 
	   << " additional damage points! " << endl;
      
      damage = 2 * damage; 
    }
  return damage;
}


// ************************************************************************
class Human : public Creature
{ 
public:
  Human();
  Human(string theSpecies, int theStrength, int theHit);
};
Human :: Human() : Creature() { }

Human :: Human(string theSpecies, int theStrength, int theHit)
  : Creature(theSpecies, theStrength, theHit) { }
// ************************************************************************


#endif   //CREATURE_HPP




