// Problem 9.8
// read a file 
// print lines, words, and frequency of words 


#include <cctype>
#include <cstdlib>
#include <cstring>
#include <string>
#include <fstream>
#include <iomanip>
#include <iostream>
using namespace std;



int main()
{
  string s;
  char c;

  int nline, nword, n;
  nline = nword = n = 0;

  const int SIZE = 1000;
  int freq[SIZE] = {0};

  string word[SIZE];

 // open a text file
  ifstream inpfile;
  inpfile.open("prob9.08.txt");

  //check for successful opening of the file 
  if ( inpfile.fail() )
    { cout << "I/O error: Input file opening failed!" << endl;
      exit(1);
    }

  while (inpfile >> s)     // read one string at a time
    {
      // read strings from the file 
      // save strings in an array 
      word[n++] = s;

      // keep track of the number of occurance of the string  
      ++freq[nword];  

      // count the number of strings 
      ++nword;   

      // if a string repeats, adjust the number of frequency  
      /*for (int i=0; i < n; i++)
	{ 
	  if (word[i] == s) 
	    { ++freq[i];
      	      cout << i << " " <<word[i] << " " << freq[i] << endl;
	    }
	}
      */

      //cout << nword << " " << s << " " << freq[nword] << endl;
 
      // get character after each string in the line
      // if it is a 'new line' character count for a line 
      // otherwise do nothing  
      inpfile.get(c);           
      if (c == '\n') ++nline;

     // go up to read the next string in the line 
    }

  //for (int i=0; i < n; i++)
  //  cout << i << " " << freq[i] << " " << word[i] << endl;
  
  // if a string repeats, adjust the number of frequency  
  for (int i=0; i < n; i++)
    {  
      s = word[i];
      for (int j=i+1; j < n; j++)
	{
	  if (word[j] == s) 
	    {
	      ++freq[i];
	     cout << j << " " << word[j] << " " << freq[i] << endl;
	    }
	}
 
     // delete all s from word and re-calculate n 
    }

  cout << "The input had " << nline << " lines, " << nword
       << " words\n"
       << "and the following letter frequencies: " << endl;
  
  
  for (int i=0; i < nword; i++)
    { s = word[i];

     if (i > 0 && i%3 == 0) cout << endl;
     cout << setw(16)  << setiosflags(ios::right)
	  << s.c_str() << ": " << setw(2) 
	  << freq[i]; 
    }
  
  inpfile.close();

  cout << endl;
  return 0;
}  


