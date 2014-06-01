// printing Characters and Strings 

#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;


int main()
{
  cout << "char* word = \"Hello\"; cout << word;" << endl;
  cout << "warning: deprecated conversion from string constant to ‘char*’";
  cout << endl;
  char* word1 = "Hello"; cout << word1;
  cout << endl; cout << endl;

  cout << "char word[]= \"Hello\"; cout << word;" << endl;
  char word2[]= "Hello"; cout << word2;
  cout << endl;

  // check
  //char word3[]= {"hello" "hello" "hello" "hello"};
  //char word4[2][5]= {'hello','hello'};
  //char word3[2][5]=
  //  { "hello",
  //    "hello"
  // };
  
  //check 
  char word4[2][5]=
    {
      {'h','e','l','l','o'},
      {'h','e','l','l','o'}
    };  

  cout << word4[1][0] << endl;
  cout << endl;


  // check
  char c[9] = "";
  cin  >> c; 
  cout << "char c[9]: " << strlen(c) << " " << c << endl; 
  if (strlen(c) == 8)
    { cout << "Thank you. Your username name is correct." << endl; }
  else
    { cout << "Invalid number of characters. Aborting ..." << endl;
      exit(1);
    }
  cout << endl;


  /*
  // check
  string s = '';
  cin  >> s; 
  cout << "string s: " << s.length() << " " << s << endl; 
  if (s.length(s) != 8)
    { cout << "Invalid number of characters. Aborting ..." << endl;
      exit(1);
    }
  */


  // check
  const int SIZE = 5;
  char ourString[SIZE] = "Hi";

  int index=0;
  while (ourString[index] != '\0' && (index < SIZE))
    { ourString[index] = 'X';
      cout << "ourString: " << ourString << endl;
      index++;
    }
  cout << "ourString: " << ourString << endl;
  cout << endl;


  //check
  char stringVar[] = "Hello";
  strcat(stringVar, " and Good-bye");
  cout << stringVar << endl;

  // check : adding two strings
  //char stringVar1[] = "Hello";         //error
  //char stringVar2[] = " and Good-bye"; //error
  string stringVar1 = "Hello";
  string stringVar2 = " and Good-bye";
  cout << stringVar1 + stringVar2 << endl;
  cout << endl;


  //check
  // Caution: you must initilize the char array 
  //          when declaring as char c[] = {'\t'}
  //          or anything with a single quote!
  // For exm: char char1[] = {'\t'}; will give 
  //          you a strange number when ask for 
  //          the 'strlen(char)'     

  char char1[10] = {'\t'};    // char char1[] = {'\t'} BAD!
  char char2[10] = {'t'};     // char char1[] = {'t'}  BAD! 
  char char3[] = "M";
  char char4[] = "Nixon\n";
  cout << strlen(char1) <<" "<< strlen(char2) <<" "
       << strlen(char3) <<" "<< strlen(char4) <<" "
       << endl;
  cout << endl;


  // check 
  cout << "printing single, double quotes: " << "\'" << ", " << "\"" << endl;
  cout << "printing back slash           : " << "\\" << endl;
  cout << "printing forward slash        : " << "/" << endl;


  cout << endl;
  return 0;
}
