// Example : 12.13
// Abstract Base Class 


#include <cstring>
#include <string>
#include <iostream>
using namespace std;


// Abstract Base Class
class Media
{
public:
  Media();
  Media(string theTitle);

  virtual void print() = 0;
  virtual const char* id()   = 0;

protected:
  string title;
};

Media :: Media() 
{ title = " " ; }
Media :: Media(string theTitle)
{ title = theTitle; }



// Derived Class Book
class Book: public Media   // -------------------------------------------
{
public:
  Book();
  Book(string theTitle, string theAuthor, 
       string thePublisher, string theIsbn);

  void print();
  const char* id();

private:
  string author, publisher, isbn;
};

Book :: Book() : Media()
{ 
  author    = " "; 
  publisher = " "; 
  isbn      = " "; 
}   

Book :: Book(string theTitle, string theAuthor, 
	     string thePublisher, string theIsbn)
  : Media(theTitle)
{
  author    = theAuthor; 
  publisher = thePublisher; 
  isbn      = theIsbn;
}   

void Book :: print()
{ 
  cout << title 
       << " is written by "    << author 
       << "\nPublished by " << publisher 
       << endl; 
}

const char* Book :: id()
{ 
  const char* c = isbn.c_str(); 
  return c; 
}    


// Derived Class Megazine 
class Megazine: public Media   // ----------------------------------------
{
public:
  Megazine();
  Megazine(string theTitle, 
	   int theVolume, int theNumber, 
	   string theIssn, string thePublisher);

  void print();
  const char* id();

private:
  int volume, number;
  string issn, publisher;
};


Megazine :: Megazine() : Media()
{ 
  volume = 0; number = 0; 
  issn= " "; publisher = " "; 
}   

Megazine :: Megazine (string theTitle, 
		      int theVolume, int theNumber, 
		      string theIssn, string thePublisher)
  : Media(theTitle)
{
  volume    = theVolume; 
  number    = theNumber;
  issn      = theIssn;
  publisher = thePublisher; 
}   


void Megazine :: print()
{
  cout << title 
       << ", vol. "   << volume  
       << ", no.  "   << number 
       << ", issn "   << issn 
       << "\nPublished by " << publisher 
       << endl; 
} 

const char* Megazine :: id()
{
  const char* c = issn.c_str();
  return c;
}





int main()
{
  Book book("The C++ Programming Language", 
	    "Bjarne Stroustrap", 
	    "Addition-Wesley", "0-201-53992-6");

  book.print();
  cout << "ISBN : " << book.id() << endl;
  cout << endl;


  Megazine megazine("TIME", 125, 12, "0040-681X", 
		    "Time-Werner");
  megazine.print();

  return 0;
}
