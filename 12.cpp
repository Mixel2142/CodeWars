/*
https://www.codewars.com/kata/count-ones-in-a-segment/train/cpp
Given two numbers: 'left' and 'right' (1 <= 'left' <= 'right' <= 200000000000000) return sum of all '1' occurencies in binary representations of numbers between 'left' and 'right' (including both)
*/
#include <math.h>
#define C55 0x5555555555555555ULL
#define C33 0x3333333333333333ULL
#define C0F 0x0f0f0f0f0f0f0f0fULL
#define C01 0x0101010101010101ULL

inline unsigned cppPopcount(unsigned bb)
{
    bb -= (bb >> 1) & C55;              // put count of each 2 bits into those 2 bits
    bb = (bb & C33) + ((bb >> 2) & C33);// put count of each 4 bits into those 4 bits
    bb = (bb + (bb >> 4)) & C0F;        // put count of each 8 bits into those 8 bits
    return (bb * C01) >> 56;            // returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ...
}

inline long long OBD(int& degree)
{
return degree*(pow(2,degree)/2)-((pow(2,degree)/4)*(degree-1));
}

long long countOnes ( int left, int right )
{
long long rt=0;
int leftb=2;
int leftd=1;
int rightb=2;
int rightd=1;

while(leftb <left){leftb*=2;leftd++;}
while(rightb <right){rightb*=2;rightd++;}




if(right-left <10000)
{
for(unsigned i=left;i<=right;i++)
rt+=cppPopcount(i);
return rt;
}

for(int i=leftd;i<=rightd;i++)rt+=OBD(i);// посчитали общую сумму в этих степенных блоках
//{
int sumL=8;
int sravn=4;
int countL=2;
while((leftb/2) + sravn <= left)
{
sumL+=(OBD(++countL)+pow(2,--countL));
sravn+=pow(2,countL);
countL++;
}
sumL-=(OBD(countL)+pow(2,--countL));
if(left-pow(2,leftd-1) == 1)rt--;
else if(left-pow(2,leftd-1) != 0)rt-=sumL;
for(unsigned i=(leftb/2) + (sravn/2);i<left;i++)rt-=cppPopcount(i);//cout <<"-cppPopcount(i)="<<cppPopcount(i)<<endl;}
/////////////////////////////////////////////////////////////} вычитаем лишнее слево
//{
 sumL=8;
 sravn=4;
 countL=2;
while((rightb/2) + sravn <= right)
{
sumL+=(OBD(++countL)+pow(2,--countL));
sravn+=pow(2,countL);
countL++;
}
sumL-=OBD(countL)+pow(2,--countL);
for(unsigned i=(rightb/2) + (sravn/2);i<=right;i++)sumL+=cppPopcount(i);

rt-=(OBD(rightd)-sumL);
//} вычитаем лишнее справо


return rt;
}
void main() 
 {
	 countOnes ( 0, 200 );
 }