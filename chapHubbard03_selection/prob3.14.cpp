// Problem 3.14, chapter 3 (C++, J. R. Hubbard) 
// Switch statement 


#include <iostream>
using namespace std;


int main ()
{
  int score;
  cout << "Enter your score: " << endl;
  cin  >> score;

  if (score < 0 || score > 100) 
    cout << "error: score is out of range" << endl;

  switch (score/10)
    {case  10:
     case   9: cout << "your grade is A" << endl;  break;
     case   8: cout << "your grade is B" << endl;  break;
     case   7: cout << "your grade is C" << endl;  break;
     case   6: cout << "your grade is D" << endl;  break;
     default : cout << "your grade is F" << endl;  break;
    }
  return 0;
}
