#include <iostream>
class Solution {
public:
    bool isPalindrome(int x) {
        if(x>9) {
            long d=1,d2=1,r=0;
            while(x/d) {
            d*=10;
            }
            while(d>1) {
            d/=10;
            r+=(((x/d2)%10)*d);
            d2*=10;
            }
            return (r==x)?1:0;
        }
        return (0>x)?0:1;
    }
};
/*
    Runtime: 4 ms, faster than 95.16% of C++ online submissions for Palindrome Number.
    Memory Usage: 5.9 MB, less than 74.26% of C++ online submissions for Palindrome Number.
*/
int main() {
    Solution s;
    std::cout << s.isPalindrome(101); //returns 1
    return 0;
}
