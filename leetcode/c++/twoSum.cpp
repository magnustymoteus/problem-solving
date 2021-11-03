#include <iostream>
#include <vector>
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++) {
            for(int j=0;j<nums.size();j++) {
                if(&nums[i]!=&nums[j]&&nums[i]+nums[j]==target) return {i,j};
            }
        }
        return {};
    }
};
int main() {
    Solution s;
    std::vector<int> n = {2,7,11,15};
    std::vector<int> r = s.twoSum(n, 9); //returns {1,0}
    /*
    Runtime: 1056 ms, faster than 5.01% of C++ online submissions for Two Sum.
    Memory Usage: 10 MB, less than 97.84% of C++ online submissions for Two Sum.
    */
    return 0;
}
