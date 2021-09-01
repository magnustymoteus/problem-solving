#include <vector>
using namespace std;
vector<vector<int> > matrixAddition(vector<vector<int> > a,vector<vector<int>> b){
  for(unsigned int i=0;i<a.size();i++) {
    for(unsigned int j=0;j<a.size();j++) {
      a[i][j] += b[i][j];
    }
  }
  return a;
}
