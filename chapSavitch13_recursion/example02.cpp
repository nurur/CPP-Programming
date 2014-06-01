// Example: Recursive Function
// Recusive Void Function: finding facotrial function 


#include <cstdlib>
#include <iostream>
using namespace std;


void recurDes( int count ) // Each call gets its own count
{
  if (count >= 1) 
    { if (count == 1) cout << count;
      else 
      cout << count << "."; 
      recurDes ( count-1 );
    }
  else return;
}


void recurAsc( int count ) // Each call gets its own count
{
  if (count <= 10)
    { if (count == 10) cout << count;
      else cout << count << "."; 
      recurAsc ( count+1 );
    }
  else return;
}

void reverse (int num)
{
  if (num < 10)
    { 
      cout << num;
    } 
  else 
    { cout << (num%10) << "";
      reverse (num/10);
    }

  //if (num > 0)
  //{ cout << (num%10) << "";
  //reverse (num/10);
  //}
  //else return;
}



void printAst (int count, int uplimit) 
{
  if (count <= uplimit)
    {
      for (int i =0; i < count; i++) 
	cout << "*";
      cout << endl;
      
      printAst (count+1, uplimit);       
    }

  else return;
}





int main()
{
  recurDes(10);  // Decrement 
  cout << endl;

  recurAsc(1);   // Increment 
  cout << endl;

  reverse(3456); // Printing Reverse
  cout << endl;


  printAst(1,10); // Printing Pins 

  cout << endl;
  return 0;
}
