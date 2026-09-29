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
    void depth(TreeNode* root, int maxSoFar){
        if (!root) return;
        if (root->val >= maxSoFar) result++;
        maxSoFar = max(maxSoFar, root->val);
        depth(root->left, maxSoFar);
        depth(root->right, maxSoFar);
    }

    int goodNodes(TreeNode* root) {
        int maxSoFar = INT_MIN;
        depth(root, maxSoFar);
        return result;
    }
};
