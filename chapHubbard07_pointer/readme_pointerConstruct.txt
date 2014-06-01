---------------------------------------------------------------------------
Note 1:
Problems 8.19 and 8.20 (Computing with C++, Chap 8, J R Hubbard)
8.19
a) A pointer to a char                   : char* pc;
b) A C-sting which can have 19 characters: string cs[19]; 
c) A pointer to a C-string               : string** pcs; 
d) A string object                       : string x;
e) A pointer to a string object          : string* ps (= &x);
f) A static array of 8 string objects    : string a[8];
g) A dynamic array of 8 string objects   : string a = new string[8];

8.20 
Assume a Person object x 
a) Initialize a pointer p point to a Person object x 
b) Assign the Person object y to the object to which p points to  
c) Initialize a pointer q to the address of the pointer p
d) Initialize a reference r to the Person object x;
Person x, y;
Person*  p = &x; 
        *p =  y;
Person** q = &p;
Person&  r =  x;



---------------------------------------------------------------------------
Note 2:
int i;         // integer variable 'i'
int *p;        // pointer 'p' to an integer
int a[];       // array 'a' of integers
int f();       // function 'f' with return value of type integer
int **pp;      // pointer 'pp' to a pointer to an integer
int (*pa)[];   // pointer 'pa' to an array of integer
int (*pf)();   // pointer 'pf' to a function with returnvalue integer
int *ap[];     // array 'ap' of pointers to an integer
int *fp();     // function 'fp' which returns a pointer to an integer
int ***ppp;    // pointer 'ppp' to a pointer to a pointer to an integer
int (**ppa)[]; // pointer 'ppa' to a pointer to an array of integers
int (**ppf)(); // pointer 'ppf' to a pointer to a function with return value 
               // of type integer
int *(*pap)[]; // pointer 'pap' to an array of pointers to an integer
int *(*pfp)(); // pointer 'pfp' to function with return value of type pointer 
               // to an integer
int **app[];   // array of pointers 'app' that point to pointers to integer 
               // values
int (*apa[])[];// array of pointers 'apa' to arrays of integers
int (*apf[])();// array of pointers 'apf' to functions with return values of 
               // type integer
int ***fpp();  // function 'fpp' which returns a pointer to a pointer to a 
               // pointer to an int
int (*fpa())[];// function 'fpa' with return value of a pointer to array of 
               // integers
int (*fpf())();// function 'fpf' with return value of a pointer to function 
               // which returns an integer
