// Example: mutableDataMember.cpp
// Mutable Data Member
// 
/*
This keyword can only be applied to non-static and non-const data members 
of a class. If a data member is declared mutable, then it is legal to 
assign a value to this data member from a const member function.
*/


class X
{
public:

   bool GetFlag() const
   {
      m_access++;
      return m_flag;
   }

private:
   mutable int m_access;
   bool m_flag;
};



int main()
{
}
