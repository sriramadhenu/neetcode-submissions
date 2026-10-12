class Solution {
public:
    struct TrieNode{
        TrieNode* children[26] = {nullptr};
        bool isEnd = false;
    };

    TrieNode* root;

    void insert(string word){
        TrieNode* curr = root;
        for (char c : word){
            int i = c - 'a';
            if (!curr->children[i]) curr->children[i] = new TrieNode;
            curr = curr->children[i];
        }
        curr->isEnd = true;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, string& current, vector<string>& result){
        if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return;
        char letter = board[r][c];
        // already used on this path - '#'
        if (letter == '#' || !node->children[letter - 'a']) return;
        node = node->children[letter - 'a'];
        current += letter;
        if (node->isEnd){
            node->isEnd = false;
            result.push_back(current);
        }
        // mark as visited
        board[r][c] = '#';
        // explore all 4 neighbors
        dfs(board, r + 1, c, node, current, result);
        dfs(board, r, c + 1, node, current, result);
        dfs(board, r - 1, c, node, current, result);
        dfs(board, r, c - 1, node, current, result);
        // restore
        board[r][c] = letter;
        current.pop_back();
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new TrieNode;
        for (string word : words) insert(word);
        vector<string> result;
        string current = "";
        for (int r = 0; r < board.size(); r++){
            for (int c = 0; c < board[0].size(); c++){
                dfs(board, r, c, root, current, result);
            }
        }
        return result;
    }
};
