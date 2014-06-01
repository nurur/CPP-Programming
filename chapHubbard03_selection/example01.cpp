// Example 3.16
// The if ... else construct 


#include <iostream>
using namespace std;


int main ()
{
  int score;
  cout << "Enter your score: " << endl;
  cin  >> score;

  if (score < 0 || score > 100) cout << "error: score is out of range" << endl;
  else if (score >= 90)                cout << "your grade is A" << endl;
  else if (score >= 80 && score < 90)  cout << "your grade is B" << endl;
  else if (score >= 70 && score < 80)  cout << "your grade is C" << endl;
  else if (score >= 60 && score < 70)  cout << "your grade is D" << endl;
  else if (score >=  0 && score < 60)  cout << "your grade is F" << endl;

  return 0;
}
