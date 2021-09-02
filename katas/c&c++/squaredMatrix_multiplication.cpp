#include <iostream>
#include <vector>
using namespace std;
vector<vector<int>> matrix_multiplication(vector<vector<int>> &a, vector<vector<int>> &b, size_t n){
  	vector<vector<int>> c;
	vector<int> temp;
	signed int sum = 0;
	unsigned int lx=0, rx=0, co=0;
	for(unsigned int i=0;i<n;i++) {
        for(unsigned int j=0;j<n;j++) {
            temp.push_back(0);
        }
        c.push_back(temp);
        temp.clear();
	}
    for(unsigned int i=0;i<n*n;i++, co++, rx++) {
        for(unsigned int j=0;j<n;j++) {
            if(co==n) lx++, co=0;
            sum += a[lx][j] * b[j][rx];
        }
        c[lx][co]=sum, sum =0;
            if(rx==n-1) rx=-1;
    }
return c;
}
int main() {


	vector<vector<int>> a = {{1,2,3},{3,2,1},{1,1,1}}; //example
    vector<vector<int>> b ={{1,2,3},{3,2,1},{1,1,1}};
	int n = a.size();
	vector<vector<int>> c = matrix_multiplication(a,b, n);
	for(unsigned int i=0;i<c.size();i++) {
		for(unsigned int j=0;j<c[i].size();j++) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
