// Example: 
// Explicit constructor 


#include <iostream>
using namespace std;


class String
{
public:
  String();
  explicit String(int n) : c(n) { }

private:
  char c;
};



int main()
{
  // With 'explicit constructor', the following with produce an error  
  String s1 = 'a';     // Error: conversion from ‘char’ to non-scalar 
                       // type ‘String’ requested

  // The following declarations are allowed 
  String s2(10);           // allowed
  String s3 = String(10);  // allowed


  return 0;  
}
