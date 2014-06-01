// Example: 7.5
// Static data field and Static member function 
// Note: 
// Static member functions can access ONLY Static data members 
// from their own Class 



#include <iostream>
using namespace std;


class Server
{
public:
  Server();
  Server(char letterName);

  void serveOne();
  static int getTurn();
  static bool stillOpen();

private:
  char name;
  static int turn;
  static int lastServed;
  static int nowOpen;

};


//Initialization of Static data member
int Server :: turn       = 0;
int Server :: lastServed = 0;
int Server :: nowOpen    = true;



Server :: Server() { name = 0; }
Server :: Server(char letterName) { }

void Server :: serveOne()
{
  if (nowOpen && lastServed < turn)
    {
      lastServed++;
      cout << "Server " << name << " now serving " 
	   << lastServed << endl;
    }
  
  if (lastServed >= turn)  nowOpen = false;
}


// Static member function 
int Server :: getTurn() 
{ 
  turn++; 
  return turn; 
}

bool Server :: stillOpen()
{ return nowOpen; }





int main()
{
  Server s1('A'), s2('B');
  int number, count;

  do
    {
      cout << "How many in your group? "; cin >> number;
      cout << "Your truns are: ";
      
      for (count=0; count < number; count++)
	cout << Server :: getTurn() << ' ';
      cout << endl;
      
      s1.serveOne();
      s2.serveOne();
      
    } while(Server :: stillOpen());
  
  cout << "Now closing service.\n";
  
  return 0;
}
