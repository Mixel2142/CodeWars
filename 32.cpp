/*
https://www.codewars.com/kata/5b0a80ce84a30f4762000069/solutions/cpp
FIXME: Hello
*/

class Dinglemouse
{
    std::string name;
    int age = 0;
    char sex;
    int chek[3]={0,0,0};
public:

    Dinglemouse()
    {
    }

    Dinglemouse &setAge(int age)
    {  
        if(chek[0] != 1 && chek[1] != 1 && chek[2] != 1)
        {
          if(chek[0] == 0) chek[0] = 1;
          else if(chek[1] == 0) chek[1]= 1;
          else if(chek[2] == 0) chek[3]= 1;
        }
        this->age = age;
        return *this;
    }

    Dinglemouse &setSex(char sex)
    {
        if(chek[0] != 2 && chek[1] != 2 && chek[2] != 2)
        {
          if(chek[0] == 0) chek[0] = 2;
          else if(chek[1] == 0) chek[1]= 2;
          else if(chek[2] == 0) chek[3]= 2;
        }
        this->sex = sex;
        return *this;
    }

    Dinglemouse &setName(const std::string &name)
    {
        if(chek[0] != 3 && chek[1] != 3 && chek[2] != 3)
        {
          if(chek[0] == 0) chek[0] = 3;
          else if(chek[1] == 0) chek[1]= 3;
          else if(chek[2] == 0) chek[3]= 3;
        }
        this->name = name;
        return *this;
    }

    std::string hello()
    {
    std::string ret = "Hello.";
    for(auto i = 0; i <= 3; i++)
    {
      switch(chek[i])
      {
        case 1:
        ret += " I am " + std::to_string(age) + '.';
        chek[i]=-1;
        break;
        
        case 2:
        ret += (std::string(" I am ") + ('M' == sex ? "male." : "female."));
        chek[i]=-1;
        break;
        
        case 3:
        ret += " My name is " + name + '.';
        chek[i]=-1;
        break;
        
        default:
        break;
      };
       
    }
     return ret;
    }
};

