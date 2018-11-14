/*
https://www.codewars.com/kata/55e2adece53b4cdcb900006c
Two tortoises named A and B must run a race. A starts with an average speed of 720 feet per hour. Young B knows she runs faster than A, and furthermore has not finished her cabbage.
When she starts, at last, she can see that A has a 70 feet lead but B's speed is 850 feet per hour. How long will it take B to catch A?
More generally: given two speeds v1 (A's speed, integer > 0) and v2 (B's speed, integer > 0) and a lead g (integer > 0) how long will it take B to catch A?
The result will be an array [hour, min, sec] which is the time needed in hours, minutes and seconds (round down to the nearest second) or a string in some languages.
If v1 >= v2 then return nil, nothing, null, None or {-1, -1, -1} for C++, C, Go, Nim, [] for Kotlin or "-1 -1 -1".
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>  
using namespace std; 
  
vector<int> race(int v1, int v2, int g)
{
  /* Numerical method
    if(v1>=v2)return vector<int> {-1,-1,-1};
     double v2_s=(double)v2/3600.0;
     double v1_s=(double)v1/3600.0;
    int sec=0;
     double rast1=7.0;
     double rast2=0.0;
    while(rast1>rast2)
    {
    rast1=(v1_s*sec)+g;
    rast2=v2_s*sec;
    sec++;
    }
   */
   if(v1>=v2)return vector<int> {-1,-1,-1};
   int  sec = floor(g/(v2-v1)*3600.0);
   return vector<int> {sec/3600,(sec%3600)/60,(sec%3600)%60};
}
 void main() 
 { 
 race(2,10,5);
 }