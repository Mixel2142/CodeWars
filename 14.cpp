/*
https://www.codewars.com/kata/5938f5b606c3033f4700015a
Introduction
There is a war and nobody knows - the alphabet war!
There are two groups of hostile letters. The tension between left side letters and right side letters was too high and the war began. The letters called airstrike to help them in war - dashes and dots are spreaded everywhere on the battlefield.
Task
Write a function that accepts fight string consists of only small letters and * which means a bomb drop place. Return who wins the fight after bombs are exploded. When the left side wins return Left side wins!, when the right side wins return Right side wins!, in other case return Let's fight again!.
The left side letters and their power:
 w - 4
 p - 3 
 b - 2
 s - 1
The right side letters and their power:
 m - 4
 q - 3 
 d - 2
 z - 1
The other letters don't have power and are only victims.
The * bombs kills the adjacent letters ( i.e. aa*aa => a___a, **aa** => ______ );
Example
AlphabetWar("s*zz");           //=> Right side wins!
AlphabetWar("*zd*qm*wp*bs*"); //=> Let's fight again!
AlphabetWar("zzzz*s*");       //=> R
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

string fightM = fight;
cout <<"OLD STR:"<<fight<<endl;

if(fight.size() >1)
for(unsigned i = 0; i < fightM.size();i++)
{
if(fightM.at(i)=='*')
{

if(i == 0 )
  {
  if(fightM.at(i+1) != '*')fightM.at(i+1)='=';
  continue;
  }  
if(i == fightM.size()-1)
  {
fightM.at(i-1)='=';break;
  }
if(fightM.at(i+1) != '*')fightM.at(i+1)='=';

fightM.at(i-1)='=';

}

}//for

cout<<endl<<"NEW STRING:"<<fightM<<endl;

int pereves=0;

for(auto &it :fightM)
{
switch(it){
//left
case 'w': pereves+=4;cout<<4<<endl;break;
case 'p': pereves+=3;cout<<3<<endl;break;
case 'b': pereves+=2;cout<<2<<endl;break;
case 's': pereves+=1;cout<<1<<endl;break;
//right
case 'm': pereves-=4;cout<<-4<<endl;break;
case 'q': pereves-=3;cout<<-3<<endl;break;
case 'd': pereves-=2;cout<<-2<<endl;break;
case 'z': pereves-=1;cout<<-1<<endl;break;
default : break;
        };
//cout <<"pereves="<<pereves<<endl;
}
//cout << pereves<<endl;
//cout <<"//////////////////////////////////////";
if(pereves == 0)return "Let's fight again!";
return pereves < 0 ? "Right side wins!" : "Left side wins!";
}


void main(int argc, char* argv[])
{
if(argc>1)cout<<alphabetWar(argv[1]);
}