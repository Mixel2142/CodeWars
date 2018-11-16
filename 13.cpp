/*
https://www.codewars.com/kata/59377c53e66267c8f6000027/solutions/cpp
Introduction
There is a war and nobody knows - the alphabet war!
There are two groups of hostile letters. The tension between left side letters and right side letters was too high and the war began.
Task
Write a function that accepts fight string consists of only small letters and return who wins the fight. When the left side wins return Left side wins!, when the right side wins return Right side wins!, in other case return Let's fight again!.
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>  
using namespace std;

string alphabetWar(string fight)
{

int pereves=0;
for(auto &it :fight)
{
switch(it)
{
//left
case 'w':pereves+=4;cout<<4<<endl;break;
case 'p':pereves+=3;cout<<3<<endl;break;
case 'b':pereves+=2;cout<<2<<endl;break;
case 's':pereves+=1;cout<<1<<endl;break;
//right
case 'm':pereves-=4;cout<<-4<<endl;break;
case 'q':pereves-=3;cout<<-3<<endl;break;
case 'd':pereves-=2;cout<<-2<<endl;break;
case 'z':pereves-=1;cout<<-1<<endl;break;
default : break;
};
cout <<"pereves="<<pereves<<endl;
}
cout << pereves<<endl;
cout <<"//////////////////////////////////////";
if(pereves == 0)return "Let's fight again!";
return pereves < 0 ? "Right side wins!" : "Left side wins!";
}

void main(string str)
{
	alphabetWar(str);
}