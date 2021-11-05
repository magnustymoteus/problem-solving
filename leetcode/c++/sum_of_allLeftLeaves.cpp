#include <iostream>
 typedef struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  } TreeNode;
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        unsigned int s=0;
        if(root->left && !root->left->left && !root->left->right)s+=root->left->val;
        if(root->right)s+=sumOfLeftLeaves(root->right);
        if(root->left)s+=sumOfLeftLeaves(root->left);
        return s;
    }
};
/*
Runtime: 4 ms, faster than 70.70% of C++ online submissions for Sum of Left Leaves.
Memory Usage: 13.4 MB, less than 77.27% of C++ online submissions for Sum of Left Leaves.
*/
int main() {
    TreeNode t(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)), new TreeNode(3));
    Solution s;
    std::cout<<s.sumOfLeftLeaves(&t); //returns 4;
    return 0;
}
