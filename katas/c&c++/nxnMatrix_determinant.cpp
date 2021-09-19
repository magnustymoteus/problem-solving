/* Calculates a determinant for a NxN matrix using a recursive function with dynamic 2D arrays and a 3D for-loop. 
To make the function syntactically compact are ternary operators used instead of repetitive conditional statements. */
#include <vector>
using namespace std;
long long determinant(vector<vector<long long>> m) {
  if(m.size() == 1) {
    return m[0][0];
  }
  else if(m.size() == 2) {
    return ((m[0][0])*(m[1][1]))-((m[1][0])*(m[0][1]));
  }
  else {
    vector<vector<long long>> m2;
    long long res = 0;
    signed short int s = 1;
    for(unsigned int fc=1;fc<=m.size();fc++) {
        for(unsigned int x=0;x<m.size()-1;x++) {
            m2.push_back(vector<long long>());
            for(unsigned int y=0;y<m.size();y++) {
                if(y!=fc-1) {
                    m2[x].push_back(m[x+1][y]);
                }
            }
        }
        res += (m[0][fc-1])*((s)*(determinant(m2))),s = (s==1)?s=-1:s=1,m2.clear();
    }
    return res;
  }
}
int main() {
    vector<vector<long long>> m = {
        {1,0,4,-6},
        {2,5,0,3},
        {-1,2,3,5},
        {2,1,-2,3}
    };
    vector<vector<long long>> m2 = {
        {2,4,-3},
        {5,7,6},
        {-8,1,9}
    };
    determinant(m);//outputs 318 (4x4 matrix)
    determinant(m2);//outputs -414 (3x3 matrix)
    return 0;
}
