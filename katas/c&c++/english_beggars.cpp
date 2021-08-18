#include <vector>
using namespace std;
vector<int> beggars(const vector<int>& values, unsigned int n){
    vector<int> result;
    unsigned int b = 0;
    if(n!=0) {
    for(unsigned int i =0;i<n;i++) {
        result.push_back(0);
    }

    for(unsigned int i=0;i<values.size();i++) {
        if(b == n) {
            b = 0;
        }
        result[b]+=values[i];
        b++;
    }
      }
    return result;
}
