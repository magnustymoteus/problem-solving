#include <vector>
using namespace std;
vector<string> wave(string y){
  vector<string> arr;
  for(int i=0;i<y.length();i++) {
    string str = y;
    if(str[i] == ' ') {
      continue;
    }
    else{
    str[i] = toupper(str[i]);
    arr.push_back(str);
      }
  }
  return arr;
}
