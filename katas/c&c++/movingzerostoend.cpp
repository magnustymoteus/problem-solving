#include <vector>
using namespace std;
vector<int> move_zeroes(const vector<int>& input) {
  int c = 0;
  vector<int> nums;
  for(unsigned long i=0;i<input.size();i++) {
      if(input[i] != 0) {
        nums.push_back(input[i]);
      }
      else if(input[i] == 0) {
        c++;
    }
  }
  for(unsigned long i=0;i<c;i++) {
    nums.push_back(0);
  }
  return nums;
}
