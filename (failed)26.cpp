#include <algorithm>


using namespace std;

void print(const vector<std::string> &lines)
{
for(auto &it:lines)
  {
    for(auto str =it.begin();str != it.end();++str)
      cout << *str;
    cout<<endl;
  }
}


size_t leftSize(const vector<string> &lines, const int itPlus)// высота левой стороны квадрата
{
  size_t cnt=0;
  for( auto &it : lines )
  {
     if(it.size() > itPlus)
       if(it.at(itPlus) == '|') cnt+=2;
  }
  return cnt;
}

size_t countSubstr(const string &str,const string sbstr)
{
  size_t cnt=0;
  size_t pos =0;
  while(pos !=  string::npos)
  {
    pos = str.find(sbstr.c_str(),pos,str.size());
    cnt++;
  }
  return cnt;
}

size_t maxSize(const vector<string> &lines)
{
  size_t maxSz=1;
  for(auto &it : lines) if(it.size() > maxSz) maxSz = it.size();
  cout<<"maxSz="<<maxSz<<endl;
  return maxSz;
}

unsigned int count_squares(const vector<string> &lines)
{

lines[0][1];
  print( lines );
  unsigned int cnt=0;
  for( auto &it : lines )
  {  
      auto LeftTopPlus = find(it.begin(),it.end(),'+');
      auto RightTopPlus = find(LeftTopPlus+1,it.cend(),'+');
      auto topSize = count(LeftTopPlus,RightTopPlus,'-');
      cout<<"topSize="<<topSize<<endl;
      auto leftSide =  leftSize(lines,distance( it.begin(),LeftTopPlus));
      cout<<"leftSide="<<leftSide<<endl;
      
  }

  return 0;
}