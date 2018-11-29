/*
https://www.codewars.com/kata/56e3cd1d93c3d940e50006a4
Input : an array of integers.
Output : this array, but sorted in such a way that there are two wings:
the left wing with numbers decreasing,
the right wing with numbers increasing.
the two wings have the same length. If the length of the array is odd the wings are around the bottom, if the length is even the bottom is considered to be part of the right wing.
each integer l of the left wing must be greater or equal to its counterpart r in the right wing, the difference l - r being as small as possible. In other words the right wing must be nearly as steeply as the left wing.
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>  
using namespace std; 

vector<int> makeValley(vector<int> &arr)
    {
		
vector<int> myarr(arr.size(),-1);
int k=0;

sort(arr.begin(),arr.end(),greater<int>());

for(auto i = 0;i<arr.size();i++)
{
if(i%2 == 0){ myarr.at(k)=arr.at(i);k++;} //если` четное
else {myarr.at(arr.size()-k)=arr.at(i);}
}
return myarr;
    }


 void main() 
 { 
 vector<int> b = {1,1,2,3};
 vector<int> a(makeValley(b));
 for(auto &it:a)cout<< it;
 }