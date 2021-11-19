#include <iostream>
#include <vector>

bool isBadVersion(int version) {
    return (version>=10)?1:0; //example
}

class Solution {
public:
    unsigned int firstBadVersion(unsigned int n) {
        long l=0,r=n,p;
        while(l<=r) {
            p=(l+r)/2;
            if(!isBadVersion(p)) l=p+1;
            else if(isBadVersion(p) && !isBadVersion(p-1)) return p;
            else r=p-1;
        }

        return p;
    }
};

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for First Bad Version.
Memory Usage: 5.7 MB, less than 89.79% of C++ online submissions for First Bad Version.
*/

int main() {
    Solution s;
    std::cout << s.firstBadVersion(10); //example, outputs 10 in ~0.040s
    return 0;
}
