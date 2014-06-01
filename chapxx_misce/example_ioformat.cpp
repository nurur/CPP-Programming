// Example


#include <iomanip>
#include <iostream>
using namespace std;


int main()
{
	int n;
	float f;
	double d;
	char s[100];

	// input an integer 
	cout << "input an integer       : "; cin >> n;
	// print an integer, no formatting 
	cout << n << endl;
	// print an integer, padded on left with spaces to total 6 chars 
	cout << setfill('-') << setw(6) << n << endl;
	// print an integer, padded on right with spaces to total 6 chars 
	cout << setw(-6) << n << endl;

	// input a string (whitespace delineated) 
	cout << "input a string         : "; cin >> s;
	// print a string, no formatting 
	cout << s << endl;
	// print a string, padded with spaces on left to 20 chars 
	cout << setw(20) << s << endl;
	// print a string, padded with spaces on right to 20 chars 
	cout << setiosflags(ios::left) << setw(20) << s << endl;

	// input a single precision floating point number 
	cout << "input a floating number: "; cin >> f;
	// print a float, default precision is 6 places 
	cout << setiosflags(ios::fixed) << f << endl;
	// input a double precision floating point number 
	cin >> d;
	// print a double, default precision is 6 places 
	cout << d << endl;
	// print a double, 2 places of precision 
	cout << setprecision(2) << d << endl;
	// print a double, 2 places of precision, padded with space to 10 
	cout << setw(10) << setprecision(2) << d << endl;

	return 0;
}
