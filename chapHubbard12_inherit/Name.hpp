// Name.hpp
// Class Name


#include <iostream>
using namespace std;


class Name
{
  friend istream& operator>>(istream&, Name&);       // input stream operator
  friend ostream& operator<<(ostream&, const Name&); // output stream operator
  
public:
  Name(char*, char*, char*, char*, char*, char*);   // constrcutor 

  void   last(string s) {   m_last = s; }           // member functions
  void  first(string s) {  m_first = s; }
  void middle(string s) { m_middle = s; }
  void  title(string s) {  m_title = s; }
  void suffix(string s) { m_suffix = s; }
  void   nick(string s) {   m_nick = s; }

  string   last() {   return m_last; }              // access functions 
  string  first() {  return m_first; }
  string middle() { return m_middle; }
  string  title() {  return m_title; }
  string suffix() { return m_suffix; }
  string   nick() {   return m_nick; }

private:
  string m_last, m_first, m_middle, m_title, m_suffix, m_nick;
};


// constructor 
Name :: Name(char* last="", char* first="", char* middle="",
	     char* title="", char* suffix="", char* nick="")
  : m_last(last), m_first(first), m_middle(middle), 
    m_title(title), m_suffix(suffix), m_nick(nick) { } 


// friend function 
// input stream operator
istream& operator>>(istream& istr, Name& x)
{ char buffer[80];

  istr.getline(buffer,80,'|');
  x.m_last   = buffer;
  istr.getline(buffer,80,'|');
  x.m_first  = buffer;
  istr.getline(buffer,80,'|');
  x.m_middle = buffer;
  istr.getline(buffer,80,'|');
  x.m_suffix = buffer;
  istr.getline(buffer,80,'|');
  x.m_title  = buffer;
  istr.getline(buffer,80,'|');
  x.m_nick = buffer;

  return istr;
}

// output stream operator
ostream& operator<<(ostream& ostr, const Name& x)
{ 
  if (x.m_title  != "")  ostr << x.m_title  << ", ";
  if (x.m_first  != "")  ostr << x.m_first  << " ";
  if (x.m_middle != "")  ostr << x.m_middle << " ";
  if (x.m_last   != "")  ostr << x.m_last   << ""; 
  if (x.m_suffix != "")  ostr << x.m_suffix << "";
  if (x.m_nick   != "")  ostr << ", \"" << x.m_nick << "\"";

  return ostr;
}
