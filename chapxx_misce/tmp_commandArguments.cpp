// Example:


#include <fstream>
#include <iostream>
using namespace std;


int main ( int argc, char* argv[] )
{
  if ( argc != 2 ) // argc should be 2 for correct execution
                   // We print argv[0] assuming it is the program name
    cout <<"usage: " << argv[0] << " <filename>\n";

  else 
    {
      // We assume argv[1] is a filename to open
      ifstream the_file ( argv[1] );
      // Always check to see if file opening succeeded
      if ( !the_file.is_open() )
	cout << "Could not open file\n";
      else 
	{ char x;
	  // the_file.get ( x ) returns false if the end of the file
	  //  is reached or an error occurs
	  while ( the_file.get(x) )
	    cout<< x;
	}
      // the_file is closed implicitly here
    }

  return 0;
}
