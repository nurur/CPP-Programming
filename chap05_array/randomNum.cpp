// use 'function' and 'for' loop to produce random numbers   

#include <cmath>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;


#define value 10

int random(int n);
int hits[value];


int main()
{
  int n;         // number to test
  int i;         // loop counter
  int r;


  //set seed for random numbers
  srand(time(NULL)); 
  

  //get a number from keyboard
  cout << "Enter a number and press Enter: ";
  cin  >> n;

  //line break
  cout << endl;


  for (i = 1; i <= n; i++)
    {
      r = random(value);
      hits[r]++;
    }
  

  // print results
  for (i = 0; i < value; i++){
      cout << i << " : " << hits[i] << " : " << "Percent: ";
      cout << hits[i]/((double) n/100) << endl;
    }
}



int random(int n) 
{
  //generate a random integer number
  // from 0 to n-1
  return rand() % n ;
}
