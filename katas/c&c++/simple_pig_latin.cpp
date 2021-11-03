#include <iostream>
std::string pig_it(std::string str){
    char c;
    std::string cstr, fstr;
   for(signed short int i=0;i<=str.size();i++) {
      if(str[i]==' ' || i==str.size()) {
          cstr+=c;
          if((c>=97&&c<=122)||(c>=65&&c<=90))cstr+="ay";
          cstr+=' ';
          fstr+=cstr;
          cstr.clear();
      }
      else if((!i || str[i-1]==' ')) {
        c=str[i];
      }
      else if(str[i] != ' ') cstr+=str[i];
   }
   return fstr.erase(fstr.size()-1);
}

int main() {
    std::cout << pig_it("! Pig Latin"); //outputs "! igPay atinLay"
    return 0;
}
