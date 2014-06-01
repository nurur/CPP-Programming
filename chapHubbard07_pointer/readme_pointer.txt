
Note 1:
double a[]
double* a, double** a, double*& a
double* a[]


double  a[5];                // array of 5 floats
double* a[5];                // array of 5 pointers to floats
double* a = new double[5];   // pointer to the location of floats 




Note 2:
a) De-referencing dangling pointer: (Bad!)
int* q; 
*q = 44;

b) De-referencing null pointer    : (Bad!)
int* r = 0;
*r = 44;

c)
string* p = new string("ABCDEF");
string& r = *p;     // synonym
string  s = *p;     // copy
string* q = &s;     // pointer

int  nn = 44;       // int
int& rn = nn;       // ref to int 
int* qq = &nn;      // ptr to int 
int& rq = *qq;      // ref to ptr
 



Note 3: 
What to pass to the function call if the argument is a 
1) single pointer-to-integer, 
2) pointer to the pointer-to-integer, 
3) reference to the pointer-to-integer, 


>
void foo_xpInt(int*   pInt);
void foo_ppInt(int** ppInt);
void foo_rpInt(int*& rpInt);

int main()
{ 
  int    n  = 44; 
  int*   p  = &n;
  int** pp  = &p;

   p  = &n;
  *p  = 44;
   pp = &p
 **pp = &n = 44;

 foo_xpInt(p );
 foo_ppInt(&p);
 foo_rpInt(p );
}
>
