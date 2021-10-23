#include <iostream>
using namespace std;

unsigned short int last_digit(const string &str1, const string &str2) {
      auto pow = [](unsigned int a, unsigned int b, auto&& pow) -> unsigned int {
      if(b>1) return a*pow(a,--b,pow);
      return (b)?a:1;};
      unsigned short int n1 = str1[str1.size()-1]-48;
      unsigned short int n2 = (str2.size()>1)? stoi((str2.substr(str2.size()-2,str2.size())))%4:(str2[str2.size()-1]-48)%4;
      return ((str1.size()==1 && str2.size()==1 && str1[0]=='0'&&str2[0]=='0')||(str2[0]=='0' && str2.size()==1))?1:(str1[0]=='0'||str1[str1.size()-1]=='0')?0: (!n2)? pow(n1,4,pow)%10 : pow(n1,n2,pow)%10;
}

int main() {
    last_digit("1606938044258990275541962092341162602522202993782792835301376", "2037035976334486086268445688409378161051468393665936250636140449354381299763336706183397376"); //returns 6
    return 0;
}
