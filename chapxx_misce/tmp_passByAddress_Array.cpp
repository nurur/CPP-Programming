// Example: Pass By Address with Arrays
//
// If a formal parameter of a function is a pointer type, the 
// parameter is passed by its address.
//
// An array passed into a function is always passed by address, 
// Since the array's name IS a variable that stores its address 
// i.e. Its is a pointer. 

#include <iostream>
using namespace std;


// Pass-by-Address as Input Parameter 
void Swap(int* list, int a, int b) // void Swap(int list[], int a, int b);
{ 
  int temp = list[a]; 
  list[a] = list[b]; 
  list[b] = temp; 
} 


// Pass-by-Address in Return  
int* ChooseList(int* list1, int* list2) 
 { 
   if (list1[0] < list2[0]) 
     return list1; 
   else 
     return list2;    // returns a copy of the address of the array 
 } 



int main()
{
  // Swap: pass-by-address as input parameter 
  int numList[5] = {2, 4, 6, 8, 10}; 
  for (int i=0;i<5; i++)
    cout << numList[i] << " ";
  cout << endl;  

  Swap(numList, 1, 4);        // swaps items 1 and 4 
  for (int i=0;i<5; i++)
    cout << numList[i] << " ";
  cout << endl;  


  // Pass-by-Address in return  
  int numbers1[5] = {1,2,3,4,5}; 
  int numbers2[3] = {3,5,7}; 
  int* p = ChooseList(numbers1, numbers2); 
 

  cout << endl;
  return 0;
}
