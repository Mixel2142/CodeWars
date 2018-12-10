/*
https://www.codewars.com/kata/sort-array-by-string-length/cpp
Write a function that takes an array of strings as an argument and returns a sorted array containing the same strings, ordered from shortest to longest.

For example, if this array were passed as an argument:

["Telescopes", "Glasses", "Eyes", "Monocles"]

Your function would return the following array:

["Eyes", "Glasses", "Monocles", "Telescopes"]

All of the strings in the array passed to your function will be different lengths, so you will not have to decide how to order multiple strings of the same length.
*/

#include <algorithm>
using namespace std;
class Kata
{
public:
    vector<string> sortByLength(vector<string> array)
    {
    vector<string> vecStr = array;
    auto isSizeMore = [](string a,string b) { return a.size() < b.size();};
    sort(vecStr.begin(), vecStr.end(),isSizeMore);
    return vecStr;
    }
};