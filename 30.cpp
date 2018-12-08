/*
https://www.codewars.com/kata/5629db57620258aa9d000014
Given two strings s1 and s2, we want to visualize how different the two strings are. We will only
take into account the lowercase letters (a to z). First let us count the frequency of each lowercase letters in s1 and s2.
s1 = "A aaaa bb c"
s2 = "& aaa bbb c d"
s1 has 4 'a', 2 'b', 1 'c'
s2 has 3 'a', 3 'b', 1 'c', 1 'd'
So the maximum for 'a' in s1 and s2 is 4 from s1; the maximum for 'b' is 3 from s2. In the following we will not consider
letters when the maximum of their occurrences is less than or equal to 1.
We can resume the differences between s1 and s2 in the following string: "1:aaaa/2:bbb" where 1 in 1:aaaa stands for string
s1 and aaaa because the maximum for a is 4. In the same manner 2:bbb stands for string s2 and bbb because the maximum for b is 3.
*/
/*
    pair  < int, int >  pr = make_pair(1, 3);
    tuple  < int, int, char >  pr = make_tuple( -cnt_s2, 2, it );
    secons - number of s1(1) or s2(2) or =(3)
    first - count(repeat)
    */
#include <map>
#include <cmath>

using namespace std;

class Mix
{
public:

   static void addIndivid( const string &s1, string &str )
  {
    for( auto &it : s1 )
      {
         if( find( str.cbegin() ,str.cend() ,it ) == str.cend() && isalpha(it) && !isspace(it) && islower(it) )
             str.push_back(it); 
      }
  }//fun


  static string multiChar( const char &sh, size_t count)
  {
    string str="";
    for( size_t i = 0; i < count; ++i )str+=sh;
    return str;
  }//fun


  static void print(map   < tuple < int, int, char >, string> strMap)
  { 
    cout<<endl;
    for( auto &it : strMap)
    {
      cout<<it.second;
    }
    cout<<endl;
  }//fun
  
  
  static string getStrFromMap(map   < tuple < int, int, char >, string > strMap)
  {
     string str = "";
     for( auto &it : strMap)
      {
        if( get<1>( it.first ) != 3 )str += to_string( get<1>( it.first ) );
        else str += "=";
        str += ":";
        str += it.second;
        str += "/";
        
      }
      str.pop_back();
    return str;
  }//fun
  
  
  static string mix( const string &s1, const string &s2 )
  {
    string str = "";
    
    addIndivid( s1, str );
    addIndivid( s2, str );
    
    sort( str.begin(), str.end() );
      
    map   < tuple < int, int, char >, string> strMap;
    
    for( auto &it : str )
      {
          int cnt_s1 = count( s1.cbegin(), s1.cend(), it ); 
          int cnt_s2 = count( s2.cbegin(), s2.cend(), it );
          
          if( cnt_s1 <= 1 && cnt_s2 <= 1)
          {
              continue;     
          }
          
          if(  cnt_s1 > cnt_s2)
          {
              tuple  < int, int, char >  pr = make_tuple( -cnt_s1, 1,  it );
              strMap[pr] = multiChar( it, cnt_s1 );
              continue;
          }
          
          if(  cnt_s1 < cnt_s2)
          {
              tuple  < int, int, char >  pr = make_tuple( -cnt_s2, 2, it );
              strMap[pr] = multiChar( it, cnt_s2 );
              continue;
          }
          
          tuple  < int, int, char >  pr = make_tuple( -cnt_s2, 3,  it );
          strMap[pr] = multiChar( it, cnt_s2 );
          
      }//forech
      
      str.clear();
      print( strMap );
      string strRt = ""; 
      strRt += getStrFromMap( strMap );
      
      return strRt;
  };//fun
};
