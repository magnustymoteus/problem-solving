
#include <vector>
using namespace std;
vector <int> josephus(vector <int> items, int k) {
   vector<int> r;
 for(int a=0, b=0;items.size();a++, b++) {
 	a=(a>items.size()-1)?0:a;
 	if(b==k-1) {
	 	b=-1;
		r.push_back(items[a]);
		items.erase(items.begin()+a);
		a--;
	}
}
  return r;
}

int main() {
	vector<int> items {
		1, 2, 3, 4, 5, 6, 7
	};
	vector<int> r = josephus(items, 3); //returns 3 6 2 7 5 1 4
	return 0;
}
