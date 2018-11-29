/*
https://www.codewars.com/kata/5886e082a836a691340000c3
Task
A rectangle with sides equal to even integers a and b is drawn on the Cartesian plane. Its center (the intersection point of its diagonals) coincides with the point (0, 0), but the sides of the rectangle are not parallel to the axes; instead, they are forming 45 degree angles with the axes.
How many points with integer coordinates are located inside the given rectangle (including on its sides)?
Example
For a = 6 and b = 4, the output should be 23
The following picture illustrates the example, and the 23 points are marked green.
Input/Output
[input] integer a
A positive even integer.
Constraints: 2 ≤ a ≤ 10000.
[input] integer b
A positive even integer.
Constraints: 2 ≤ b ≤ 10000.
[output] an integer
The number of inner points with integer coordinates.
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <math.h>
#include <bitset>
#include <vector>

using namespace std;

long long rectangle_rotation(double a, double b)
{
const double diag=1.414213;

cout<<a<<" "<<b<<endl;
int pointsA =( a/diag < 0.707106 ? (int)(a/diag) : (int)(a/diag)+1);
cout<<"pointsA="<<pointsA<<endl;
int pointsB =( b/diag < 0.707106 ? (int)(b/diag) : (int)(b/diag)+1);
cout<<"pointsB="<<pointsB<<endl;
  if(pointsB%2 == pointsA%2)return pointsA*pointsB+(pointsA-1)*(pointsB-1);
  else return pointsA*pointsB+(pointsA-1)*(pointsB-1)-1;
}

void main(int argc, char* argv[])
{
if(argc > 2)cout<<"Points in rectangle(45)="<<rectangle_rotation(atoi(argv[1]),atoi(argv[2]));
}