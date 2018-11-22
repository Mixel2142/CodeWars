/*
https://www.codewars.com/kata/57eadb7ecd143f4c9c0000a3
Write a function to convert a name into initials. This kata strictly takes two words with one space in between them.
The output should be two capital letters with a dot seperating them.
It should look like this:
Sam Harris => S.H
Patrick Feeney => P.F
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>  
using namespace std; 

string abbrevName(string name)
{
string str;
if(name.size()>0)
{
str=name.substr(0,1)+".";
for(int i=0;i<name.size()-1;i++){if(name.at(i)==' '){str+=name.substr(i+1,1);break;}}
str[0]=toupper(str[0]);
str[2]=toupper(str[2]);
return str;
}
return "";
}

 void main()
 { 
 cout<<abbrevName("Pepa Moningstar");
 }