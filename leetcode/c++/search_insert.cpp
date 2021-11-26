#include <iostream>
#include <vector>
class Solution {
public:
    unsigned int searchInsert(std::vector<int>& nums, signed int target) {
        signed int p, l=0, r=nums.size()-1;
        while(l<=r) {
            p=(l+r)/2;
            if (nums[p]==target) return p;
            (target>nums[p])?l=p+1:r=p-1;
        }
        return r+1;
    }
};
/*Runtime: 4 ms, faster than 80.56% of C++ online submissions for Search Insert Position.
Memory Usage: 9.6 MB, less than 94.77% of C++ online submissions for Search Insert Position.*/
int main() {
    std::vector<int> n = {1,3,5,6};
    Solution s;
    std::cout << s.searchInsert(n,2); //outputs 1
    return 0;
}
