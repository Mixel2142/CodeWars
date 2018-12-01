/*
https://www.codewars.com/kata/57a1fd2ce298a731b20006a4
Write function isPalindrom that checks if a given string (case insensitive) is a palindrom.
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>  
using namespace std; 

bool isPalindrom (const string& str)
{
 if(str.size() <= 1)return true;

 for(int i =0; i< str.length()/2; i++)
 {
 if(toupper(str.at(str.length()-1-i)) != toupper(str.at(i)))return false;
 }

 return true;
}

 void main(int argc, char* argv[])
 { 
 if(argc>1)cout<<isPalindrom (argv[1]);
 }