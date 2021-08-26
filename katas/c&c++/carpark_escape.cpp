#include <string>
#include <vector>
using namespace std;

vector<string> escape(const vector<vector<int>> &carpark)
{
    vector<string> route;
    string r, d = "D1";
    signed int s[2];
    for(unsigned int i=0;i<carpark.size();i++) {
        for(unsigned int j=0;j<carpark[i].size();j++) {
            if(carpark[i][j] == 2) {
                s[0] = i, s[1] = j;
                break;
            }
        }
    }
    for(signed int i=s[0];i<carpark.size();i++) {
        for(signed int j=0;j<carpark[i].size();j++) {
            if(carpark[i][j] == 1) {
                if(s[1]-j<0) {
                    r="R";
                    r += to_string(j-s[1]);
                    s[1] = j;
                    if(d != "D1" && carpark[i+1][j] != 1) {
                        route.push_back(d);
                        d = "D1";
                    }
                    route.push_back(r);
                    if(carpark[i+1][j] != 1 && d == "D1") {
                    route.push_back(d);
                    d = "D1";
                    }
                }
                else if(s[1]-j>0){
                    r="L";
                    r+=to_string(s[1]-j);
                    s[1] = j;
                    if(carpark[i+1][j] != 1 && d != "D1") {
                    route.push_back(d);
                    d = "D1";
                    }
                    route.push_back(r);
                   if(carpark[i+1][j] != 1 && d == "D1") {
                    route.push_back(d);
                    d = "D1";
                    }
                }
                else if(s[1]-j==0) {
                    d[1] = (char) ((int)d[1]+1);
                }
                i++,j=-1;
            }
        }
    }
    r = "R";
    if(d != "D1") {
        route.push_back(d);
    }
    if(s[1]!=carpark[carpark.size()-1].size()-1) {
        r += to_string(carpark[carpark.size()-1].size()-1-s[1]);
        route.push_back(r);
    }
    return route;
}
