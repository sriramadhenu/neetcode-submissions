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

class Codec {
public:
    void preOrder(TreeNode* root, string& str){
        if (!root){
            str += "#, ";
            return;
        };
        str += to_string(root->val) + ", ";
        preOrder(root->left, str);
        preOrder(root->right, str);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string str = "";
        preOrder(root, str);
        return str;
    }
    
    TreeNode* buildTree(vector<string>& tokens, int& pos){
        if (tokens[pos] == "#"){
            pos++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(tokens[pos]));
        pos++;

        node->left = buildTree(tokens, pos);
        node->right = buildTree(tokens, pos);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> tokens;
        stringstream ss(data);
        string token;
        while (getline(ss, token, ',')){
            // get rid of leading whitespace if it exists
            if (!token.empty() && token[0] == ' ') token = token.substr(1);
            tokens.push_back(token);
        }

        int pos = 0;
        return buildTree(tokens, pos);
    }
};
