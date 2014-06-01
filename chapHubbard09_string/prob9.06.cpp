// Problem 9.6
// read a file 
// print lines, words, and frequency of capital letters


#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;




int main()
{
  string s;
  char c;

  int lines, words, len;
  lines = words = 0;

  const int SIZE=91;
  int freq[SIZE] = {0};


 // open a text file
  ifstream inpfile;
  inpfile.open("prob9.6.txt");

  //check for successful opening of the file 
  if ( inpfile.fail() )
    { cout << "I/O error: Input file opening failed!" << endl;
      exit(1);
    }

  while (inpfile >> s)      // read the file, one string at a time
    {
      // read strings from a given line and count  
      ++words;                    
      
      // get character after each string in the line
      // if it is a 'new line' character count for a line 
      // otherwise do nothing  
      inpfile.get(c);           
      if (c == '\n') ++lines;
      
      // go through each character of the string
      // if it is a capitol letter count
      // otherwise do nothing 
      len = s.length();
      for (int i = 0; i < len; i++)
	{
	  c = s[i];                      
	  if (islower(c)) c = toupper(c); // if lowercase, then capitalize c
	  if (isupper(c)) ++freq[c];      // count c
	}

     // go up to read the next string in the line 
    }
  

  cout << "The input had " << lines << " lines, " << words 
       << " words\n"
       << "and the following letter frequencies: " << endl;

  for (int i=65; i < SIZE; i++)
    {
      cout << char(i) << ":" << freq[i] << "  ";
      if (i%10 == 0) cout << endl;
    }

  inpfile.close();
  return 0;
}  


