/* Fraction Class
program with 'inline' functions
int get_num() and int get_den() are inlined
*/


#include <stdlib.h>
#include <iostream>
using namespace std;


class Fraction {
private:             // data members
  int num, den;
  
public:              // function members 
  void set(int n, int d){
    num = n; den = d; 
    normalize();}               //inline
  
  int get_num() {return num;}   //inline
  int get_den() {return den;}   //inline

private:
  void normalize();
  int gcf(int a, int b);
  int lcm(int a, int b);
};



int main() {
  int a, b;
  char str[80];
  Fraction fract;
  
  while (1){
    cout << "Enter Numerator  : ";
    cin >> a;
    cout << "Enter Denomenator: ";
    cin >> b;
    
    fract.set(a,b);
    cout << "Numerator is  : " << fract.get_num() << endl;
    cout << "Denomenator is: " << fract.get_den() << endl;
    
    
    cout << "Do it again? ( Y or N): ";
    cin >> str;
    if ( !(str[0] =='Y' || str[0] =='y') )
    break;
  }
  //main program ends 
}



//----------------------------------------
// Fraction class functions
//----------------------------------------
void Fraction::normalize() {
  
  // handle cases involving 0
  if (den == 0 || num == 0){
    num = 0;
    den = 1;
  }
  
  // put negaticve sign in the numerator only 
  if (den < 0) {
    num *= -1;
    den *= -1;
  }

  int n= gcf(num, den);
  num = num / n;
  den = den / n;
}


// greatest common factor 
int Fraction::gcf(int a, int b){
  if (a % b == 0)
    return abs(b);
  else
    return gcf(b, a % b);
}



// lowest common multiple
int Fraction::lcm(int a, int b){
  return (a / gcf(a,b)) * b;
}
