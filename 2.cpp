/*
https://www.codewars.com/kata/5262119038c0985a5b00029f
Define a function isPrime/is_prime() that takes one integer argument and returns true/True or false/False depending on if the integer is a prime.
Per Wikipedia, a prime number (or a prime) is a natural number greater than 1 that has no positive divisors other than 1 and itself.
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std; 

bool isPrime(int num) {
std::cout<<num<<std::endl;
if(num<=1)return false;
if(num == 2 || num == 3 ||num == 5 ||num == 7 )return true;
if(num%2==0)return false;
for(int i=3;i<=sqrt(num);i+=2)if(num%i==0)return false;
return true;
}

 void main(int argc, char* argv[]) 
 { 
 if(argc>1)cout<<isPrime(atoi(argv[1]));
 }