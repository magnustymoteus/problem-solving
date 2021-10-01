#include <string>
#include <algorithm>
using namespace std;

pair<string, int> encode(const string &s) {
    if(s.size()) {
    string s1=s,s2=s1;
    string sArr[s.size()];
    signed int n, in;
      for(unsigned int j=0;j<s.size();j++) {
    for(unsigned int i=0;i<s.size();i++) {
        n = (i+1>=s.size())? i+1-s.size():i+1,s2[n] = s1[i];
    }
    sArr[j] = s2,s1=s2;
    }
    sort(sArr, sArr+sArr[0].size()), s1.clear();
    for(unsigned int i=0;i<s.size();i++) {
        s1+=sArr[i][sArr[0].size()-1];
        if(sArr[i] == s) in = i;
    }
    return {s1, in};
   }
    return {s,0};
}


string decode(const string &s, int n) {
  if(s.size()) {
    string s1[s.size()];
    for(unsigned short int i=0;i<s.size();i++) {
  for(unsigned short int j=0;j<s.size();j++) {
    s1[j].insert(0,1,s[j]);
  }
  sort(s1,s1+sizeof(s1)/sizeof(s1[0]));
}
  return s1[n];
  }
  return "";
}

int main() {
    pair<string, int> encoded = encode("bananabar"); //returns "nnbbraaaa" and 4
    string decoded = decode(encoded.first, encoded.second); //returns "bananabar"
    return 0;

}
