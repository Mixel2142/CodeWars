/*
https://www.codewars.com/kata/53ee5429ba190077850011d4
Code as fast as you can! You need to double the integer and return it.
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <math.h>
#include <bitset>
#include <vector>

using namespace std;

int32_t double_integer(int32_t n)
{
  return n<<1;
}

void main(int argc, char* argv[])
{
if(argc > 1)cout<<double_integer(atoi(argv[1]));
}