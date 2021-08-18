#include <string>
#include <vector>
std::vector<std::string> solution(const std::string &s)
{
    std::vector<std::string> arr;
    for(unsigned i=0;i<s.size();i+=2) {
      if(s.size()%2!=0 && i == s.size()-1) {
        break;
      }
      std::string ts;
      ts = s[i];
      ts += s[i+1];
      arr.push_back(ts);
    }
    if(s.size()%2!=0) {
      std::string ls;
      ls = s[s.size()-1];
      ls+='_';
      arr.push_back(ls);
    }
    return arr;
}
