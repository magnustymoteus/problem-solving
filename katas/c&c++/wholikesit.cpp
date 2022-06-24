#include <iostream>
#include <vector>
#include <memory>
#include <string>

std::string likes(const std::vector<std::string> &names)
{
    if(names.size()) {
    std::string resStr;
    int16_t loopEnd = (names.size()>=4)?3:names.size();
    for(int16_t i=0;i<loopEnd;i++) {
      std::string currName = (i==2 && (names.size())>=4)?"and "+std::to_string(names.size()-i)+" others":names[i];
      resStr += ((names.size()-i)==1 && names.size()>1)?"and "+currName+" ":(!i && names.size()>2)?currName+", ":currName+" ";
    }
    return (names.size()==1)?resStr+"likes this":resStr+"like this";
  }
    return "no one likes this";
}
int main() {
    std::vector<std::string> names = {"Paul", "James"}; //example
    std::cout << likes(names);
    return 0;
}
