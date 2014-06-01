// Example : 
// Shuffling array elements randomly 
/*
 * http://www.mikeware.us/cpp/?p=49
 * There are two ways to do Shuffle:
 
 * The first way would be to choose a number at random within the proper 
 * range and place it in the array in position 0; repeat this process and 
 * place the next random number in position 1, 2, 3, up to the size-1.

 * This first option could work, but duplicate values must be avoided  
 * when choosing the numbers at random (which can be inefficient).

 * The second way would be to randomly choose a position (0 to size-1) 
 * and swap the value in that position with that in the “last” position 
 * (size - 1). Next, randomly select another position (0 to size-2) and 
 * swap its value with the one in the next-to-last position. 
 * Repeat this process until position 1 is reached.
 */

#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;



void shuffleRandom(int arr[], int size)
{
   int temporary;
   int randomNum;
   int last;

   unsigned seed = time(NULL);
   srand(seed);

   for (last = size; last > 1; last--)
   {
     randomNum      =  rand() % last;    // Step 1 : Select a postion randomly 
     
     temporary      =  arr[randomNum];   // Step 2 : Swap values bewteen that  
     arr[randomNum] =  arr[last - 1];    // position and the last position
     arr[last - 1]  =  temporary;
   }
}


int main()
{
  const int SIZE = 10;
  int a[SIZE] = { 34, 12, 89, 22, 21, 45, 55, 93, 27, 76 };
  for (int i = 0; i<SIZE; i++)
    cout << a[i] << "  ";
  cout << endl;


  shuffleRandom(a,SIZE);
  for (int i = 0; i<SIZE; i++)
    cout << a[i] << "  ";
  cout << endl;

  return 0;
}
