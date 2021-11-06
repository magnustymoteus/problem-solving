#include <iostream>
#include <vector>
class Solution {
public:
    int search(std::vector<int>& nums, int target) {
        signed int l=0,r=nums.size()-1,p;
        while(l<=r) {
            p=(l+r)/2;
            if(nums[p]==target) return p;
            (target>nums[p])?l=p+1:r=p-1;
        }
        return -1;
    }
};
/*
Runtime: 28 ms, faster than 96.73% of C++ online submissions for Binary Search.
Memory Usage: 27.5 MB, less than 92.12% of C++ online submissions for Binary Search.
*/
int main() {
    Solution s;
    std::vector<int> n = {1,2,3,4,5,6,7,8,9,10};
    std::cout << s.search(n,4); //returns 3
    return 0;
}
