/*
https://www.codewars.com/kata/51b62bf6a9c58071c600001b/solutions/cpp
Create a function taking a positive integer as its parameter and returning a string containing the Roman Numeral representation of that integer.
Modern Roman numerals are written by expressing each digit separately starting with the left most digit and skipping any digit with a value of zero. 
In Roman numerals 1990 is rendered: 1000=M, 900=CM, 90=XC; resulting in MCMXC. 
2008 is written as 2000=MM, 8=VIII; or MMVIII. 1666 uses each Roman symbol in descending order: MDCLXVI.
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>  
using namespace std;

string GetRomanNumber(const string &strN,int reg=0)
{
cout << __func__<<"\t const string &strN="<<strN<<endl;
cout << __func__<<"\t reg="<<reg<<endl;
string str="";

if(strN.at(reg) == '4'){
cout<<"switch1:"<<endl;
switch(strN.size()-(reg))
{
case 1:str.append("IV");
break;
case 2:str.append("XL");
break;
case 3:str.append("CD");
break;
default : str.append("1");
};
                      }
					  
else if(strN.at(reg) == '9'){
cout<<"switch2:"<<endl;
switch(strN.size()-(reg))
{
case 1:str.append("IX");
break;
case 2:str.append("XC");
break;
case 3:str.append("CM");
break;
default : str.append("2");
};
                          }
						  
else{
	
int regN = (strN.at(reg)-'0');
cout << __func__<<"\t regN="<<regN<<endl;

if(regN-5 >= 0 ){
cout<<"switch3:"<<endl;
switch(strN.size()-(reg))
{
case 1:str.append("V");regN-=5;
break;
case 2:str.append("L");regN-=5;
break;
case 3:str.append("D");regN-=5;
break;
default: str.append("3");
};
for(unsigned i=0;i<regN;i++){
cout<<"switch4:"<<endl;
switch(strN.size()-(reg))
{
case 1:str.append("I");
break;
case 2:str.append("X");
break;
case 3:str.append("C");
break;
case 4:str.append("M");
break;
default: str.append("4");
};}
                }// regN-5 >= 0 
				
else{
for(unsigned i=0;i<regN;i++){
cout<<"switch5:"<<endl;
switch(strN.size()-(reg))
{
case 1:str.append("I");
break;
case 2:str.append("X");
break;
case 3:str.append("C");
break;
case 4:str.append("M");
break;
default: str.append("5");
};  
							}//for
    }//else
		
	}//else
		
cout << __func__<<"\t str="<<str<<endl;

return strN.size() != reg+1 ? str + GetRomanNumber(strN,reg+1) : str;
}

string solution(int number){
	
cout <<" 1 : I"<<"\t 5 : V"<<"\n 10 : X"<<"\t 50 : L"<<"\n 100 : C"<<"  500 : D"<<"\n 1000 : M"<<endl<<endl;
cout << __func__<<"\t number="<<number<<endl;

string str=to_string(number);
cout << __func__<<"\t str="<<str<<endl;

return GetRomanNumber(str);
}

void main(int argc, char* argv[])
{
if(argc>1)cout<<endl<<solution(atoi(argv[1]));
}