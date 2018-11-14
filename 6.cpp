/*
https://www.codewars.com/kata/514b92a657cdc65150000006
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
Finish the solution so that it returns the sum of all the multiples of 3 or 5 below the number passed in.
Note: If the number is a multiple of both 3 and 5, only count it once.
Courtesy of ProjectEuler.net
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>  
using namespace std; 

int solution(int number) 
{
cout <<"number="<<number<<endl;
int ret=0;
bool fl=true;
for(int i=3;i<number;i++)
{
cout <<i<<endl;;
if(i%3==0)ret+=i;
else if(i%5==0)ret+=i;
}

return ret;
}
 void main() 
 { 
 solution(20); 
 }