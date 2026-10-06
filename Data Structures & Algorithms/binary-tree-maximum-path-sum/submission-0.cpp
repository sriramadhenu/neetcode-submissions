/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int maxSum = INT_MIN;

    int subTreePath(TreeNode* node){
        if (!node) return 0;

        int left = subTreePath(node->left);
        int right = subTreePath(node->right);
        maxSum = max(maxSum, node->val + max(left, 0) + max(right, 0));
        return node->val + max(max(left, right), 0);
    }

    int maxPathSum(TreeNode* root) {
        subTreePath(root);
        return maxSum;
    }
};
