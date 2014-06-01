// Problem   : 14.10
// Inheritance 
// Base Class Pet


#ifndef PET_HPP
#define PET_HPP


#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


class Pet
{
public:
  Pet();
  Pet(string theName, int theAge, int theWeight);

  string  getName();
  int     getAge();
  int    getWeight();

  void   setName(string newName);
  void    setAge(int     newAge);
  void setWeight(int  newWeight);


  string getLifespan();


private:
  string name;
  int age;
  int weight;
};

Pet :: Pet() : name(" "), age(0), weight(0) { } 

Pet :: Pet(string theName, int theAge, int theWeight)
   :  name(theName), age(theAge), weight(theWeight) { } 

string Pet ::     getName() { return name;   }
int Pet    ::      getAge() { return age;    }
int Pet    ::   getWeight() { return weight; }

void Pet   ::     setName(string newName) { name   = newName;   }
void Pet   ::      setAge(int     newAge) { age    = newAge;    }
void Pet   ::   setWeight(int  newWeight) { weight = newWeight; }

string Pet ::  getLifespan()
{
  string s;
  s = "Unknown lifespan";
  return s;
}



class Dog : public Pet
{
public:
  Dog();
  Dog(string theName, int theAge, int theWeight, string theBreed);

  string getBreed();
  void setBreed(string newBreed);
  

  string getLifespan();


private:
  string breed;
};

Dog :: Dog() : Pet(), breed(" ") { }
Dog :: Dog(string theName, int theAge, int theWeight, string theBreed)
  : Pet(theName, theAge, theWeight), breed(theBreed) { }

string Dog :: getBreed()   
{ return breed;     }

void Dog :: setBreed(string newBreed) 
{ breed = newBreed; }  

string Dog ::  getLifespan()
{
  string s;
  if ( getWeight() > 100 )
    {
      s = "Approximately 7 years";
    }
  if ( getWeight() < 100 )
    {
      s = "Approximately 13 years";
    }
  return s;
}


#endif  // PET_HPP
