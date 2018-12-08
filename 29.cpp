/*
https://www.codewars.com/kata/password-system/train/cpp
// check symmetry
*/

class Crisis{
public:
static std::string helpZoom(std::vector<int> key){

  for(size_t i = 0; i < key.size(); i++)
  {
       if(key.at(i) != key.at(key.size()-(i+1))) return "No"; 
  }
  return "Yes";
}
};