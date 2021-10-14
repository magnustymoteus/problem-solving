#include <vector>
using namespace std;

class TreeNode 
{
  public:
    TreeNode *m_left;
	TreeNode *m_right;
	int m_value;
    TreeNode(int value, TreeNode* left, TreeNode* right)
      : m_value(value), m_left(left), m_right(right)
    {
    }
    
    TreeNode(int value)
      : m_value(value), m_left(NULL), m_right(NULL)
    {
    }
    
};

class Solution {
	public:
	static TreeNode* arrayToTree(vector<int> arr, unsigned int i=0) {
	TreeNode *root = NULL;
	if(i<arr.size()) {
		root = new TreeNode(arr[i]);
		root->m_left = Solution::arrayToTree(arr, i*2+1);
		root->m_right = Solution::arrayToTree(arr, i*2+2);
	}
	return root;
	}
};
int main() {
    vector<int> arr = {17, 0, -4, 3, 15};
	TreeNode *binTree = Solution::arrayToTree(arr); 
	/*outputs the following binary tree:
	17
   /  \
  0   -4
 / \
3   15 
	*/
		/*The static method of the solution class uses recursion to determine the succeeding children. If the current index is smaller than the size of the vector array, then the child is the integer at the index position of the vector array argument. The next left child is determined by self-multiplication by 2 and subsequent incrementation by 1, while for the right child the index is multiplied by 2 and incremented by the same number afterwards.
	
	This challenge was slightly harder due to my previous unfamiliarity with binary trees and tree data stuctures in general.
	*/
	return 0;
}