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
    int result = 0;

    int depth(TreeNode* root, int maxSoFar){
        if (!root) return 0;
        if (root->val >= maxSoFar) result++;
        maxSoFar = max(maxSoFar, root->val);
        int left = depth(root->left, maxSoFar);
        int right = depth(root->right, maxSoFar);
        return 1 + max(left, right);
    }

    int goodNodes(TreeNode* root) {
        int maxSoFar = INT_MIN;
        int a = depth(root, maxSoFar);
        return result;
    }
};
