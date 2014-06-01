#include <iostream>

using namespace std;

// All three of the following functions will attempt to double the
// arguments that are passed in from the main program

void PassByValue(int a, int b)
// Receives parameters passed by value
{
   a = a * 2;
   b = b * 2;

   cout << "\nLocal parameters:   a = " << a << "  b = " << b << endl;
   cout << "Leaving PassByValue function\n";
}

void PassByReference(int& a, int& b)
// Receives parameters passed by reference
{

   a = a * 2;
   b = b * 2;

   cout << "\nLocal parameters:   a = " << a << "  b = " << b << endl;
   cout << "Leaving PassByReference function\n";
}

void PassByAddress(int* a, int* b)
// Receives parameters passed by address (i.e. pass by pointer)
{

   (*a) = (*a) * 2;
   (*b) = (*b) * 2;

   cout << "\nLocal parameters:  *a = " << *a << "  *b = " << *b << endl;
   cout << "Leaving PassByAddress function\n";
}

void ShowMenu()
{
   cout << "\n\t(a) Pass By Value\n";
   cout << "\t(b) Pass By Reference\n";
   cout << "\t(c) Pass By Address\n";
   cout << "\t(x) Exit\n";
   cout << "\nPlease enter option:  ";
}

int main()
{
   int x, y;			
   int *p, *q;
   p = &x;				// p points to x
   q = &y;				// q points to y

   cout << "\nVaribles x and y created.  Pointers p and q created.\n";
   cout << "p points to x.   q points to y.\n";

   char option;

   do
   {
	ShowMenu();
	cin >> option;		// get command
	cin.get();		// discard newline

	if (option != 'x')
	{
		cout << "Enter value for x: ";
		cin >> x;
		cout << "Enter value for y: ";
		cin >> y;
		cout << endl;

		switch (option)
		{
		    case 'a':
			cout << "Calling PassByValue(x, y)\n";
			PassByValue(x,y);
			cout << "\nMain program variables:  ";
			cout << "x = " << x << "  y = " << y << endl;
			break;

		    case 'b':
			cout << "Calling PassByReference(x, y)\n";
			PassByReference(x,y);
			cout << "\nMain program variables:  ";
			cout << "x = " << x << "  y = " << y << endl;
			break;

		    case 'c':
			cout << "Calling PassByAddress(p, q)\n";
			PassByAddress(p,q);
			cout << "\nMain program variables:  ";
			cout << "x = " << x << "  y = " << y << endl;
			break;
		
		    default:
			cout << "Not a valid option.  Try again.\n";
		}
	}

   } while (option != 'x');
	
   cout << "Bye!\n";

   return 0;
}
