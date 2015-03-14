// LeetCode binary-tree-maximum-path-sum
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

// Definition for binary tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int maxPathSum(TreeNode * root) {
		int sum = INT_MIN;
		_maxPathSum(root, sum);
		return sum;
	}

	int _maxPathSum(TreeNode * root, int &sum) {
		if (root == NULL) return 0;
		int leftlen = _maxPathSum(root->left, sum);
		int rightlen = _maxPathSum(root->right, sum);
		int temp = max(root->val, max(leftlen, rightlen) + root->val);
		sum = max(sum, max(leftlen, 0) + max(rightlen, 0) + root->val);
		return temp;
	}

	int max(int a, int b) {
		return ((a > b) ? a : b);
	}
};

int main() {
	Solution s;
	TreeNode * root = new TreeNode(-2);
	root->right = new TreeNode(-3);
	//root->right = new TreeNode(3);
	cout << s.maxPathSum(root) << endl;

	return 0;
}