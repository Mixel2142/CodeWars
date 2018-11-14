/*
https://www.codewars.com/kata/55fd2d567d94ac3bc9000064
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>  
using namespace std; 

long long rowSumOddNumbers(unsigned n){
  if(n==1)return 1;
  return(n*n*n);
}

 void main() 
 { 
 rowSumOddNumbers(25);
 }