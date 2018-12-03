/*
https://www.codewars.com/kata/last-digit-of-a-huge-number/train/cpp
For a given list [x1, x2, x3, ..., xn] compute the last (decimal) digit of x1 ^ (x2 ^ (x3 ^ (... ^ xn))).
e.g: last_digit([3, 4, 2]) == 1 because 3 ^ (4 ^ 2) = 3 ^ 16 = 43046721.
Beware: Powers grow incredibly fast. For example, 9 ^ (9 ^ 9) has more than 369 millions of digits. lastDigit has to deal with such numbers efficiently.
Assume 0 ^ 0 = 1 and treat empty list as equals to 1.
This kata generalizes Last digit of a large number; you may find useful to solve it beforehand.
*/

#include <list>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;

/*
имеет значение только последняя цифра в числе для степени(в данной задаче)

4^1=4  4^2=..6  4^3=..4         и т.д. повторение
6^1=6  4^2=..6  4^3=..6         и т.д. повторение
7^0=1  7^1=..7  7^2=..9 7^2=..3 и т.д. повторение
9^0=1  9^1=9                    и т.д. повторение
разобрался с
nun 0  1  5  6  
*/
int last_digit(list<int> array) {

for(auto &it:array)cout<<it;
cout<<endl;

if(array.empty())  return 1;
if(array.front()%10 == 1)  return 1;
if(array.front()%10 == 5)  return 5;
if(array.front()%10 == 6)  return 6;
if(array.front() == 0)
{
auto isZero=[](const int &val){return val==0;};
std::list<int>::iterator finZ = find_if_not(array.begin(),array.end(),isZero);
return  ((*finZ)%2 ==0);
}//if



auto it = array.end();--it;
if(array.front()%10 == 0 )return -1;


    
  
 
    
    return -220;
}