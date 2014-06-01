// Problem 10.5 
// Person Class 


#include <cstring>
#include <iostream>
using namespace std;


class Person
{
public :
  Person(char*, int, int);
  //Person(char* nm=0, int yb=0, int yd=0): _name(nm), yob(yb), yod(yd) { }; 
                                                    // default constructor
  Person(const Person&);                            // copy constructor
 ~Person() { delete [] _name; }                     // destructor 

  char* name() { return _name; }                    // access function
  int ybirth() { return  _yob; }
  int ydeath() { return  _yod; }

  void   print();

private:
  int   _len;  // number of non-null character in the "_name"
  char* _name;
  int   _yob;
  int   _yod;
};



int main()
{
  Person P("John", 1969, 2013);
  P.print();

  return 0;
}



// constructor 
Person :: Person(char* name, int yob, int yod)
  : _len( strlen(name) ), 
    _name( new char[_len+1] ), 
    _yob(yob), 
    _yod(yod)
{ memcpy (_name, name, _len+1);
}

// copy constructor 
Person :: Person(const Person& psn) 
  : _name(psn._name), 
    _yob(psn._yob), 
    _yod(psn._yod),  
    _len(psn._len) 
{ }


void Person :: print()
{
  cout << "name           : " << _name << endl;
  cout << "year of birth  : " <<  _yob << endl; 
  cout << "year of death  : " <<  _yod << endl;
  cout << "no. characters : " <<  _len << endl;
}


