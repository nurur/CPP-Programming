// Example: 9.6
// FILE I/O


#include <cctype>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;


int main()
{
  string s;
  char c;  

  // reading from & writing to a text file
  ifstream inpfile;
  ofstream outfile;

  inpfile.open("ex03inp.txt");
  outfile.open("ex03out.txt");

  //check for successful opening of the files 
  if ( inpfile.fail() )
    { cout << "I/O error: Input file opening failed!" << endl;
      exit(1);
    }
  
  if ( outfile.fail() )
    { cout << "I/O error: Output file opening failed!" << endl;
      exit(1);
    }


  while (inpfile >> s)    //while ( inpfile.good() )
    { 
      // read a string. 
      // if the first letter is lower case, change it to upper  
      if( islower(s[0]) ) s[0] = toupper(s[0]);

      // now put the string in the output file   
      outfile << s;     

      // but there is a white space char after that string!
      // so get that character
      inpfile.get(c);   
                        
      // put that character after the string
      outfile.put(c);
   
      // go up to read the next string in the line 
    }  
  
  inpfile.close();
  outfile.close();

  //****************************************************************

  // writing to a text file
  ofstream myfile;
  myfile.open ("ex03write.txt");   //create a new file

  myfile << "writing this line to the file \"example.txt\".\n";

  myfile.close();                  //close the file

  //****************************************************************


  cout << endl;
  return 0;
}
