#include <string>
#include <vector>
using namespace std;

string alphabetWar(string fight)
{
    char lp[100] = {'s','b','p','w'};
    char rp[100] = {'z','d','q','m'};
    vector<int> tr;
    int ls=0, rs=0;
    for(int i=0;i<fight.length();i++) {
        if(fight[i] == '*') {
            tr.push_back(i);
        }
    }
    for(int i=0;i<tr.size();i++) {
        if(tr[i]==0) {
                fight[tr[i]+1] = '_';
            }
            else if(i==fight.length()-1) {
                fight[tr[i]-1] = '_';
            }
            else {
                fight[tr[i]-1] = '_';
                fight[tr[i]+1] = '_';
            }
            fight[tr[i]] = '_';
    }
    for(int i=0;i<fight.length();i++) {
        for(int j=0;j<sizeof(lp)/sizeof(lp[0]);j++) {
            if(fight[i]==lp[j]) {
                ls+=j+1;
            }
            else if(fight[i]==rp[j]) {
                rs+=j+1;
            }
        }
    }
    if(ls > rs) return "Left side wins!";
    else if(rs > ls) return "Right side wins!";
    else return "Let's fight again!";
}
