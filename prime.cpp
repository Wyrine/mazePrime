/*Prime class method definitions
  prime.cpp
*/

//including the prime class header file
#include "prime.h"

//defining the namespace used
using namespace std;

//constructor definition with one argument
Prime::Prime(int n){
  //assigning a value to checkPrime
  checkPrime = n;
  //if checkPrime is >= 1 then it can be a prime number
  if(n >= 1)//call primeCheck with the number
    primeCheck(checkPrime-1);
  else//otherwise the number cannot be prime
    cout << checkPrime << " is not a prime number.\n";
}

//Prime function that has a void return
//the function is recursive and checks to see if the passed
//is evenly divisible by n, if so then it is not prime
void Prime::primeCheck(int n){
  //base case for the recursive function. If n is one or 0 then
  //the number is prime
  if (n==1 || n==0){
    cout << checkPrime << " is a prime number.\n";
    return;
  }
  //if checkPrime is not evenly divisible by n, call
  //this function with n-1
  if((checkPrime % n) != 0) primeCheck(n-1);
  //otherwise checkPrime is not prime
  else cout << checkPrime << " is not a prime number.\n";
}
