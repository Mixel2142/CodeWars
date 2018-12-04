#include <list>
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

/*
имеет значение только последняя цифра в числе для степени(в данной задаче)
2^1=2  2^2=4  2^3=8  2^4=..6    и т.д. повторение
3^1=3  3^2=9  3^3=7 3^4=..1     и т.д. повторение
4^1=4  4^2=..6         и т.д. повторение
7^0=1  7^1=..7  7^2=..9  7^3=..3  7^4=..1  7^5=..7  7^6=..9  7^7=..3   7^8=..1  и т.д. повторение период 4
9^0=1  9^1=9                    и т.д. повторение
разобрался с
nun 0  1  2  3  4  5  6  10
*/
void print(list<int> &array)
{
  cout<<endl;
  for(auto &it: array)
    cout<<it<<"\t";
  cout<<endl;
}

char recPeriod(const int &num,const char &per,char counter = 0)
{

cout<<"recPeriod "<<num<<" : "<<(int)per<<" : "<<(int)counter<<endl;

  if(num%per == 0)
  {
    return counter;
  }
  else 
  {
    return recPeriod(num-1,per,counter+1);
  }
}


bool isZero(const int &val)
{
  return val==0;
}

int recPow(list<int> &array, int pw)
{
print(array);

if(!array.empty())
  array.pop_back();

if(array.empty())
  return pw;

if(array.back() == 0)
  return recPow(array,!pw%2);

cout<<"array.back()%10="<<array.back()%10<<endl;
switch(array.back()%10){

case  1: 
  return 1;

case  2:
  return recPow(array,pow(2,recPeriod(pw,4)));
  
case  3:
  return recPow(array,pow(3,recPeriod(pw,4)));

case  4:
  return recPow(array,pow(4,recPeriod(pw,2)));

case  5:
  return recPow(array,pw == 0 ? 1 : 5);

case  6:
    return recPow(array,pw == 0 ? 1 : 6);

case  7:
  return recPow(array,pow(7,recPeriod(pw,3)));
  
case  0:
    return recPow(array,pw == 0 ? 1 : array.back()%100);
// прописать случаи для 100 и 10 *(в общем подумать)
default : 
  return 33;
};

}

int last_digit(list<int> array)
{
if(array.empty())
  return 1;
  
return (int)recPow(array,array.back());
}


