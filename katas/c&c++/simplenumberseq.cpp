#include <string>
using namespace std;

int missing(string s) {
    string s1, s2;
    int mn = -1;
    unsigned int d = 1, c=1, mnc=0;
    while(mnc<=1 && d <= s.size()/2) {
        for(unsigned int i=0;i<=s.size();i++, c++) {
            if(s1.size() == d && s2.size() == d) {
                if((stoi(s1)>=stoi(s2) && stoi(s2+s[i])-stoi(s1)!=1 && stoi(s2+s[i])-stoi(s1)!=2) || (stoi(s2)-stoi(s1))>2) {
                    mn = -1, d++, i=0, mnc=0;
                }
                else if(stoi(s2+s[i])-stoi(s1)==1 || stoi(s2+s[i])-stoi(s1)==2) {
                    if(stoi(s2+s[i])-stoi(s1)==2) {
                        mnc++;
                        mn = stoi(s1)+1;
                    }
                    s2+=s[i];
                    d++;
                    i-=d-1;
                }
                else if(stoi(s2)-stoi(s1)==2) {
                    mnc++;
                    mn = stoi(s1)+1;
                    i-=d;
                }
                else {
                    i-=d;
                }
                s1="",s2="";
                c=1;
            }
            if(c<=(d*2)/2) {
                s1 += s[i];
            }
            else {
                s2 += s[i];
            }
        }
            if(mnc==1) {
            return mn;
        }
        else {
            break;
        }
    }
  return -1;
}