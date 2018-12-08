/*
https://www.codewars.com/kata/5324945e2ece5e1f32000370/train/cpp
Given the string representations of two integers, return the string representation of the sum of those integers.
For example:
sumStrings('1','2') // => '3'
A string representation of an integer will contain no characters besides the ten numerals "0" to "9".
*/
#include <string>

using namespace std;

unsigned toInt(const char &a)
{
    return a-'0';
}

string sum_strings(string a, string b)
{
  string stra = a;
  string strb = b;
  if( a.size() < b.size() )
  {
    for(size_t i = 0; i < b.size()-a.size(); i++)
    {
      stra.insert (stra.begin(), '0' );
    }//for
  }//if
  else
  {
  for(size_t i = 0; i < a.size()-b.size(); i++)
    {
      strb.insert (strb.begin(), '0' );
    }//for
  }//else
  string strSum = "";
  cout<<"first="<<stra<<endl;
  cout<<"second="<<strb<<endl;
   
  auto fir = 0 ;
  for( size_t i = stra.size()-1 ; i != string::npos ; --i )
  {
    fir += toInt(stra.at(i)) + toInt(strb.at(i)) ;
    cout<<"fir="<<fir<<endl;
    if( fir >= 10)
    {
      strSum.insert (strSum.begin(), '0' + fir%10 );
      fir = (fir/10)%10;
    }
    else
    {
    strSum.insert (strSum.begin(), '0' + fir);
    fir = 0;
    }
  }//for
  if( fir != 0 )strSum.insert (strSum.begin(), '0' + fir%100);
  cout<<"fir="<<fir<<endl;
  strSum.erase(0, min(strSum.find_first_not_of('0'), strSum.size()-1));
  return strSum;
}