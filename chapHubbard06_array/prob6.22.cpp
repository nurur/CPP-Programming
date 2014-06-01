// Problem: 6.22,  chaper 6 (C++, J Hubbard)
// Finding prime number using the Sieve of Eratosthenes 
// Note:
// ( (i%10) == 0 ? '\n' : ' ')
// When i=10, 20, etc., this condition is true and '\n' is assigned
// for all other values of i the condition is flase and ' ' is assigned  


#include <iomanip>
#include <iostream>
using namespace std;


void sieveOfEratosthenes(bool isPrime[], int n)
{
  int i, p, q;

  isPrime[0] = false;
  isPrime[1] = false;  
  for (i=2; i<n; i++) 	
    isPrime[i] = true;
  
  for (p=2; p<n/2; p++) 	
    for (q=2*p; q<n; q += p)	
      isPrime[q] = false; 
}


void print(bool a[], int n)
{
  int i;
  for (i=1; i<n; i++) 	
    if (a[i]) cout << setw(4) << i; 
    else cout << setw(4) << ( (i%10) == 0 ? '\n':' ');
}




int main()
{ 
  int i;
  const int SIZE = 100;
  bool isPrime[SIZE] = {0};
  
  sieveOfEratosthenes(isPrime, SIZE);
  print(isPrime, SIZE);


  cout << endl;
  return 0;
}
