// Problem 3.9, chapter 3 (C++, J. R. Hubbard) 
// program uses if ... else statement 


#include <iostream>
using namespace std;


enum Choice {ROCK, PAPER, SCISSORS};
enum Winner {PLAYER1, PLAYER2, TIE};


int main ()
{
  int m, n;
  Choice choice1, choice2;
  Winner winner;

  cout << "choose rock (0), paper (1), or scissors(2)" << endl;
  cout << "player #1: ";
  cin  >> m;
  choice1 = Choice(m);

  cout << "player #2: ";
  cin  >> m;
  choice2 = Choice(m);


  /* SOLUTION USING NESED IF STATEMENTS
    if (choice1 == choice2) winner = TIE;
    else if (choice1 == ROCK)
    if (choice2 == PAPER) winner = PLAYER2;
    else winner = PLAYER1;
    else if (choice1 == PAPER)
    if (choice2 == SCISSORS) winner = PLAYER2;
    else winner = PLAYER1;
    else if (choice1 == SCISSORS)
    if (choice2 == ROCK) winner = PLAYER2;
    else winner = PLAYER1;

    if (winner == TIE)          cout << "players tied"  << endl;
    else if (winner == PLAYER1) cout << "player #1 wins" << endl;
    else cout << "player #2 wins" << endl;
  */



  /* SOLUTION USING COMPOUND STATEMENT 
   if (choice1 == choice2) winner = TIE;
   if (choice1 == ROCK     && choice2 == PAPER)    winner = PLAYER2;
   if (choice1 == ROCK     && choice2 == SCISSORS) winner = PLAYER1; 
   if (choice1 == PAPER    && choice2 == SCISSORS) winner = PLAYER2;
   if (choice1 == PAPER    && choice2 == ROCK)     winner = PLAYER1;
   if (choice1 == SCISSORS && choice2 == ROCK)     winner = PLAYER2;
   if (choice1 == SCISSORS && choice2 == PAPER)    winner = PLAYER1;

   if (winner == TIE)          cout << "players tied"  << endl;
    else if (winner == PLAYER1) cout << "player #1 wins" << endl;
    else cout << "player #2 wins" << endl;
  */



  /* SOLUTION USING SWITCH STATEMENT 
  n = choice1 - choice2;
  switch (n)
    {case  0: winner = TIE;     break;
	
    case  +1:
    case  -2: winner = PLAYER1; break;
      
    case  -1:
    case  +2: winner = PLAYER2; break;
    }

    if (winner == TIE)          cout << "players tied"  << endl;
    else if (winner == PLAYER1) cout << "player #1 wins" << endl;
    else cout << "player #2 wins" << endl;
  */



  // SOLUTION USING CONDITIONL EXPRESSION STATEMENT 
  n     = (choice1 - choice2 + 3) % 3;
  //cout << n << endl;
  winner= (n==0 ? TIE : (n==1 ? PLAYER1:PLAYER2));
  
  if (winner == TIE)          cout << "players tied"  << endl;
  else if (winner == PLAYER1) cout << "player #1 wins" << endl;
  else cout << "player #2 wins" << endl;


  return 0;
}
