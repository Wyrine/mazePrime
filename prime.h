/*Prime class definition for prime number checking
  prime.h
*/
//make sure this file is only defined once
#pragma once

//header files needed for this class
#include <iostream>

using namespace std;

//class definition
class Prime{
  //the number that will be checked to see if it's prime or not
  int checkPrime;
public:
  //defining a constructor
  Prime(int n);
  //the recursive function definition to check if it's prime
  void primeCheck(int n);
};
