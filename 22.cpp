/*
https://www.codewars.com/kata/5b55c49d4a317adff500015f
You have the radius of a circle with the center in point (0,0).
Write a function that calculates the number of points in the circle where (x,y) - the cartesian coordinates of the points - are integers.
Example: for radius = 2 the result should be 13.
0 <= radius <= 1000
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <math.h>
#include <bitset>
#include <vector>

using namespace std;

int pointsNumber(int radius)
{
  int radius2 = radius * radius;
  unsigned count = 0;
  for (int y = -radius; y <= radius; ++y)
    for (int x = -radius; x <= radius; ++x)
    {
      bool is_inside = x * x + y * y <= radius2;
      count += is_inside;
    }
  return count;
}

void main(int argc, char* argv[])
{
if(argc > 1)cout<<pointsNumber(atoi(argv[1]));
}