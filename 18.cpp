/*
https://www.codewars.com/kata/buying-a-car/train/cpp
Let us begin with an example:
A man has a rather old car being worth $2000. He saw a secondhand car being worth $8000. He wants to keep his old car until he can buy the secondhand one.
He thinks he can save $1000 each month but the prices of his old car and of the new one decrease of 1.5 percent per month. Furthermore this percent of loss increases by 0.5 percent at the end of every two months. Our man finds it difficult to make all these calculations.
Can you help him?
How many months will it take him to save up enough money to buy the car he wants, and how much money will he have left over?
Parameters and return of function:
parameter (positive int, guaranteed) startPriceOld (Old car price)
parameter (positive int, guaranteed) startPriceNew (New car price)
parameter (positive int, guaranteed) savingperMonth 
parameter (positive float or int, guaranteed) percentLossByMonth
nbMonths(2000, 8000, 1000, 1.5) should return [6, 766] or (6, 766)
where 6 is the number of months at the end of which he can buy the new car and 766 is the nearest integer to 766.158 (rounding 766.158 gives 766).
Note:
Selling, buying and saving are normally done at end of month. Calculations are processed at the end of each considered month but if, by chance from the start, the value of the old car is bigger than the value of the new one or equal there is no saving to be made, no need to wait so he can at the beginning of the month buy the new car:
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <math.h>
#include <bitset>
#include <vector>

using namespace std;

vector<int> nbMonths(int startPriceOld, int startPriceNew, int savingperMonth, double percentLossByMonth)
{
double o=startPriceOld,n=startPriceNew,save=0;

cout<<"startPriceOld="<<startPriceOld<<endl;
cout<<"startPriceNew="<<startPriceNew<<endl;
cout<<"savingperMonth="<<savingperMonth<<endl;
cout<<"percentLossByMonth="<<percentLossByMonth<<endl;

double p=percentLossByMonth/100.0;

unsigned step=0;
bool fl=false;
while(step != 1000)
{
if(o+save >= n)break;
if(fl){p+=0.005;fl=false;}
else fl=true;
n-=n*p;
o-=o*p;
save+=savingperMonth;
step++;

}
cout<<"PriceNewCar="<<n<<endl;
cout<<"ost="<<(o+save)-n<<endl;
int res=round((o+save)-n);
return{(int)step,res};
}
void main(int argc, char* argv[])
{
if(argc > 4)nbMonths(atoi(argv[1]),atoi(argv[2]),atoi(argv[3]),atof(argv[4]));
}