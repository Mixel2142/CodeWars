/*
https://www.codewars.com/kata/57658bfa28ed87ecfa00058a/train/cpp
You are at position [0, 0] in maze NxN and you can only move in one of the four cardinal directions (i.e. North, East, South, West). Return the minimal
 number of steps to exit position [N-1, N-1] if it is possible to reach the exit from the starting position. Otherwise, return false in JavaScript/Python 
 and -1 in C++/C#/Java.
Empty positions are marked .. Walls are marked W. Start and exit positions are guaranteed to be empty in all test cases.
*/
#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;


unsigned int North ;  // Верх
unsigned int East  ;  // Право
unsigned int South ;  // Низ
unsigned int West  ;  // Лево
vector<bool> mapSteps;// карта шагов


int findShortPath(const string &maze,int pos = 0 )
{
  
}

void printMaze(const string &maze)
{
string::size_type counter=0;
cout<<endl<<"\t///NEW MAZE///"<<endl;
for(auto &it : maze )
{
cout<<it;
if(it != '\n'){
cout<<counter<<"\t";
counter++;
              }//if
}//for
}//fun

void printVec(const vector<bool> &mas ,const bool &str = 0)/* if str==0 вывод в строчку иначе в столбик*/
{
cout<<endl;
if(str){
string::size_type st=sqrt(mas.size());
string::size_type count=0;
for(auto it:mas)
{
count++;
cout<<it;
if(st==count){cout<<"\n"; st+=st;}
}//for
      }//if
else
{
for(auto it:mas)cout<<it;
cout<<endl;
}//else
}//fun

int path_finder(string maze) {

printMaze(maze);

if(maze.empty()) return -1;
if(maze.at(0) != '.') return -1;
if(maze.at(maze.size()-1) != '.') return -1;

North =-sqrt(maze.size()-count(maze.begin(),maze.end(),'\n'));  // Верх !!!!здесь ошибки т.к. size() содержит знаки отступа!(их считать не нужно)
East  =1;  // Право
South =sqrt(maze.size()-count(maze.begin(),maze.end(),'\n'));  // Низ
West  =-1;  // Лево
mapSteps.resize(maze.size()-count(maze.begin(),maze.end(),'\n'),0);
printVec(mapSteps,1);


return 4;
}
void main(int argc, char* argv[])
{
//if(argc > 2)cout<<"Points in rectangle(45)="<<rectangle_rotation(atoi(argv[1]),atoi(argv[2]));
}