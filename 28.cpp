/*
https://www.codewars.com/kata/highest-and-lowest/train/cpp
In this little assignment you are given a string of space separated numbers, and have to return the highest and lowest number.
Example:
highAndLow("1 2 3 4 5");  // return "5 1"
highAndLow("1 2 -3 4 5"); // return "5 -3"
highAndLow("1 9 3 4 -5"); // return "9 -5"
*/
#include <string>
#include <algorithm>
using namespace std;

string highAndLow(const string& numbers){
istringstream bar(numbers);
vector<int> vec{istream_iterator<int>(bar), istream_iterator<int>()};
auto max = max_element(begin(vec),end(vec));
auto min = min_element(begin(vec),end(vec));
vec.clear();
int imin=static_cast<int>(*min);
int imax=static_cast<int>(*max);
return {to_string(imax)+" "+to_string(imin)};
}