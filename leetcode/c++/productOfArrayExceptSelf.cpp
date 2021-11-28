#include <iostream>
#include <vector>
class Solution {
public:
    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        signed int *lp = new signed int[nums.size()], *rp = new signed int[nums.size()];
        std::vector<int> output(0);
        lp[0]=1,rp[nums.size()-1]=1;
        for(unsigned int i=1;i<nums.size();i++)lp[i]=lp[i-1]*nums[i-1];
        for(signed int i=nums.size()-2;i>=0;i--)rp[i]=rp[i+1]*nums[i+1];
        for(unsigned int i=0;i<nums.size();i++)output.push_back(lp[i]*rp[i]);
        return output;
    }
};
/*Runtime: 12 ms, faster than 99.44% of C++ online submissions for Product of Array Except Self.
Memory Usage: 26 MB, less than 7.54% of C++ online submissions for Product of Array Except Self.*/
int main() {
    Solution s;
    std::vector<int> items = {4,5,1,8,2};
    s.productExceptSelf(items);
    return 0;
}
