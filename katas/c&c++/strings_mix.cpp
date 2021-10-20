#include <vector>
#include <tuple>
using namespace std;
class Mix
{
public:

  static string mix(const string &s1, const string &s2) {
    auto sortTuple = [](vector<tuple<char, unsigned short int, unsigned int>> &tVect) -> void {
        for(unsigned int i=0;i<tVect.size();i++) {
            for(unsigned int j=0;j<tVect.size();j++) {
                if(get<2>(tVect[i]) < get<2>(tVect[j]) && i<j) {
                    swap(tVect[i], tVect[j]);
                }
                if(get<1>(tVect[i]) > get<1>(tVect[j]) && i<j && get<2>(tVect[i]) == get<2>(tVect[j])) {
                    swap(tVect[i], tVect[j]);
                }
                if(get<0>(tVect[i]) > get<0>(tVect[j]) && i<j && get<2>(tVect[i]) == get<2>(tVect[j]) && get<1>(tVect[i]) == get<1>(tVect[j])) {
                    swap(tVect[i], tVect[j]);
                }
            }
        }
    };
    vector<vector<pair<char, unsigned int>>> pArr;
    vector<tuple<char,unsigned short int, unsigned int>> rt;
    const string strs[2] = {s1,s2};
    string rStr;
    for(unsigned int i=0;i<2;i++) {
        vector<pair<char,unsigned int>> arr;
        for(unsigned int j=0;j<strs[i].size();j++) {
            bool f=0;
            for(unsigned int x=0;x<arr.size();x++) {
                if(strs[i][j] == arr[x].first) {
                    arr[x].second++, f=1;
                }
            }
            if(!f && ((unsigned int)strs[i][j] >= 97 && (unsigned int)strs[i][j] <= 122)) {
                    pair<char, unsigned int> p;
                    p.first = strs[i][j], p.second=1;
                    arr.push_back(p);
            }
        }
        pArr.push_back(arr);
    }
    for(signed int i=0, a=0, b=1;i<pArr[a].size();i++) {
        bool f=0;
        for(unsigned int j=0;j<pArr[b].size();j++) {
            if(pArr[a][i].first == pArr[b][j].first && ((pArr[a][i].second > 1)||(pArr[b][j].second > 1))) {
                tuple<char, unsigned short int, unsigned int> t;
                get<0>(t)=pArr[a][i].first, get<1>(t)=(pArr[a][i].second>pArr[b][j].second)?1:(pArr[b][j].second>pArr[a][i].second)?2:3,get<2>(t)=max(pArr[a][i].second, pArr[b][j].second);
                rt.push_back(t), f=1;
                pArr[a].erase(pArr[a].begin()+i), pArr[b].erase(pArr[b].begin()+j), j--,i--;
            }
        }
        if(!f && pArr[a][i].second > 1) {
            tuple<char, unsigned short int, unsigned int> t;
            get<0>(t)=pArr[a][i].first, get<1>(t)=a+1,get<2>(t) = pArr[a][i].second;
            rt.push_back(t);
            pArr[a].erase(pArr[a].begin()+i),i--;
        }
        if(i==pArr[a].size()-1 && !a) a=1, b=0,i=-1;
    }
    sortTuple(rt);
    for(unsigned int i=0;i<rt.size();i++) {
        rStr+=(get<1>(rt[i])==3)?"=:":to_string(get<1>(rt[i]))+":";
        for(unsigned int j=0;j<get<2>(rt[i]);j++) {
            rStr+=get<0>(rt[i]);
        }
        rStr+=(i!=rt.size()-1)?"/":"";
    }
    return rStr;
}};

int main() {
    Mix::mix("In many languages", "there's a pair of functions"); //example
     return 0;
}

