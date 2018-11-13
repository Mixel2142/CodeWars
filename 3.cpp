/*
https://www.codewars.com/kata/549ee8b47111a81214000941
Given two different positions on a chess board, find the least number of moves it would take a knight to get from one to the other. 
The positions will be passed as two arguments in algebraic notation. For example, knight("a3", "b5") should return 1.
The knight is not allowed to move off the board. The board is 8x8.
For information on knight moves, see https://en.wikipedia.org/wiki/Knight_%28chess%29
For information on algebraic notation, see https://en.wikipedia.org/wiki/Algebraic_notation_%28chess%29
(Warning: many of the tests were generated randomly. If any do not work, the test cases will return the input, output, and expected output; please post them.)
*/
#include <iostream>
#include <math.h>
#include <string>
#include <vector>

using namespace std; 

int knight(std::string start, std::string finish) {

 int steps=0;
 int sx=(start.at(0)-'a')+1;
 int sy=(start.at(1)-'0');
 int fx=(finish.at(0)-'a')+1;
 int fy=(finish.at(1)-'0');
 cout<<"start= "<<sx<<":"<<sy<<endl;
 cout<<"finish= "<<fx<<":"<<fy<<endl;
 if(sx==fx && sy==fy){cout<<"return="<<0+steps<<endl<<endl;return 0+steps;}
 start:
 if((abs(sx-fx) == 1 && abs(sy-fy) == 0)||(abs(sy-fy) == 1 && abs(sx-fx) == 0) ){cout<<"first_return="<<3+steps<<endl<<endl<<endl;return 3+steps;}//1)когда рядом но не по диагонали
 else if(((abs(sx-fx)+abs(sy-fy)) == 2)&& sx!=fx && sy!=fy && (((sx==1 && sy==1) || (sx==1 && sy==8) || (sx==8 && sy==1) || (sx==8 && sy==8))||((fx==1 && fy==1) || (fx==1 && fy==8) || (fx==8 && fy==1) || (fx==8 && fy==8)))){cout<<"second_return="<<4+steps<<endl<<endl;return 4+steps;}//2)когда рядом по диагонали и конь в углу или финал в углу
 else if((abs(sx-fx) == 2 && abs(sy-fy) == 0)||(abs(sy-fy) == 2 && abs(sx-fx) == 0) ){cout<<"third_return="<<2+steps<<endl<<endl;return 2+steps;} //3)когда по прямой(не диагональ) между 2 кв
 else if((abs(sx-fx) == 2 && abs(sy-fy) == 1)||(abs(sy-fy) == 2 && abs(sx-fx) == 1) ){cout<<"fourth_return="<<1+steps<<endl<<endl;return 1+steps;}//4)когда остался 1 ход
 else if((abs(sx-fx) == 2 && abs(sy-fy) == 2)  && steps ==0 ){cout<<"fifth_return="<<4+steps<<endl<<endl;return 4+steps;}                                        //5)когда по диагонали между 1 кв(частный случай от 1+шаг)
 else if((abs(sx-fx) == 3 && abs(sy-fy) == 1)||(abs(sy-fy) == 3 && abs(sx-fx) == 1) ){cout<<"sixth_return="<<2+steps<<endl<<endl;return 2+steps;} //6)когда можно дойти одной буквой Г, но большая её сторона =4(а не 3)
 else if((abs(sx-fx) == 3 && abs(sy-fy) == 2)||(abs(sy-fy) == 3 && abs(sx-fx) == 2) ){cout<<"seventh_return="<<3+steps<<endl<<endl;return 3+steps;}//7) когда можно дойти одной буквой Г, c сторонами 2 и 4
 else if((abs(sx-fx) == 3 && abs(sy-fy) == 0)||(abs(sy-fy) == 3 && abs(sx-fx) == 0) ){cout<<"eighth_return="<<3+steps<<endl<<endl;return 3+steps;}//8)когда на 1 прямой, но между 2 кв
 else if((abs(sx-fx) == 2 && abs(sy-fy) == 2)  && steps >= 1){cout<<"ninth_return="<<2+steps<<endl<<endl;return 2+steps;}                          //9)когда из-за последнего шага полуичлось по диагонали между 1 кв? но его не нужно было туда делать
 else if(((abs(sx-fx)+abs(sy-fy)) == 2)&& sx!=fx && sy!=fy ){cout<<"tenth_return="<<2+steps<<endl<<endl;return 2+steps;}                          //10)когда рядом по диагонали и конь не в углу и финал не в углу
 else {//else5
 
 if(abs(sx-fx)>abs(sy-fy)){
                           if((sx-fx)>0)sx-=2;
                           else sx+=2;
                           if((sy-fy)>=0)sy-=1; //возможен выход за доску
                           else sy+=1;
                           }
                           
 else                     {
                          if((sy-fy)>0)sy-=2;
                          else sy+=2;
                          if((sx-fx)>=0)sx-=1; //возможен выход за доску
                          else sx+=1;
                         }  
        cout<<"go to= "<<sx<<":"<<sy<<endl;
        steps++;
       goto start;
     }//else5
 
 cout<<endl<<"return="<<-1;return -1;
}//end


 void main() 
 { 
 cout<< knight("a2","c5");
 }