/*
https://www.codewars.com/kata/521c2db8ddc89b9b7a0000c1
Snail Sort
Given an n x n array, return the array elements arranged from outermost elements to the middle element, traveling clockwise.
array = [[1,2,3],
         [4,5,6],
         [7,8,9]]
snail(array) #=> [1,2,3,6,9,8,7,4,5]
For better understanding, please follow the numbers of the next array consecutively:
array = [[1,2,3],
         [8,9,4],
         [7,6,5]]
snail(array) #=> [1,2,3,4,5,6,7,8,9]
This image will illustrate things more clearly:
NOTE: The idea is not sort the elements from the lowest value to the highest; the idea is to traverse the 2-d array in a clockwise snailshell pattern.
NOTE 2: The 0x0 (empty matrix) is represented as [[]]
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <math.h>
#include <bitset>
#include <vector>

using namespace std;

vector<int> snail(vector<vector<int>> array) {
vector<int>::size_type arsz = array.size()*array.at(0).size();
if(arsz>0){
cout<<"width="<<array.size()<<" height="<<array.at(0).size()<<endl;
for(auto j=0;j<array.size();j++)
{
for(auto i=0;i<array.at(j).size();i++)
{
cout<<"\t"<<array.at(j).at(i);
}
cout<<endl;
}

vector<int> snlrt;snlrt.reserve(arsz);
vector<int>::size_type count=0;
cout<<"arsz="<<arsz<<endl;

while(snlrt.size()<arsz){
for(auto It=count;It <array.size()-count ; It++)//горизонталь верхняя
snlrt.push_back(array.at(count).at(It));
if(snlrt.size()>=arsz)break;
for(auto It=count;It <array.size()-count-1; It++)///вертикаль правая
snlrt.push_back(array.at(It+1).at(array.size()-count-1));
if(snlrt.size()>=arsz)break;
for(auto It=count+1;It <array.size()-count; It++)///горизонталь нижняя
snlrt.push_back(array.at(array.size()-count-1).at(array.size()-It-1));
if(snlrt.size()>=arsz)break;
for(auto It=count+2;It <array.size()-count ; It++)//вертикаль левая
snlrt.push_back(array.at(array.size()-It).at(count));
count++;
}

return snlrt;
}
return {};
}

void main(int argc, char* argv[])
{
for(auto &it:snail({{2,3,1},{1,2,1},{1,3,1}}))cout<<"\t"<<it;
}