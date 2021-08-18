#include <string>


std::string to_camel_case(std::string text) {
  for(int i=0;i<=text.size();i++) {
        if(text[i] == '-' || text[i] == '_') {
            text[i+1] = toupper(text[i+1]);
            text.erase(text.begin()+i);
        }
    }
  return text;
}
