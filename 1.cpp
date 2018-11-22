/*
https://www.codewars.com/kata/55911ef14065454c75000062
This is the first part. You can solve the second part here when you are done with this. Multiply two numbers! Simple!
The arguments are passed as strings.
The numbers may be way very large
Answer should be returned as a string
The returned "number" should not start with zeros e.g. 0123 is invalid
Note: 100 randomly generated tests!
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std; 

int getTryStrLong(string str)
{
for(int i=0;i<str.size();++i)if(str.at(i) !='0')return i;
return 0;
}

string multiply(string a, string b) {
 cout<<"a="<<a<<endl; cout<<"b="<<b<<endl;
 string aa=a.substr(getTryStrLong(a),a.size());
 reverse(aa.begin(), aa.end());
 string bb=b.substr(getTryStrLong(b),b.size());
 reverse(bb.begin(), bb.end());
 if(aa.size() == 1&& aa.at(0)=='0')return "0";
 if(bb.size() == 1&& bb.at(0)=='0')return "0";
 int length=aa.length()+bb.length()+1;
 vector<int> big_number(length,0);
 
   for (int i = 0; i < aa.length(); i++)
   for (int j = 0; j < bb.length(); j++)
   big_number.at(i + j) += (aa.at(i)-'0') * (bb.at(j)-'0');
   
 
for (int i = 0; i < length-2; i++)
{
    big_number.at(i+1) +=  big_number.at(i) / 10;
    big_number.at(i) %= 10;
}

  while ( big_number.at(length-1) == 0)
  length-- ;
  
 
 reverse(big_number.begin(), big_number.end());
 big_number.erase(big_number.begin(),big_number.begin()+big_number.size()-length);
 string str(length,'0');
 for (int i = 0; i < length; ++i)str.at(i)=big_number.at(i)+'0';
 
 return str;
}

 void main(int argc, char* argv[]) 
 { 
 cout<<multiply("2","12");
 }