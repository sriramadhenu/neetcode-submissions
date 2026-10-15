class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        function<bool(int, int, int)> dfs = [&](int r, int c, int index){
            if (index == word.size()) return true;
            if (r < 0 || c < 0 || r >= board.size() || c >= board[0].size()) return false;
            char letter = board[r][c];
            if (word[index] != letter) return false;

            board[r][c] = '#';
            bool ok = dfs(r + 1, c, index + 1) || dfs(r - 1, c, index + 1) || dfs(r, c + 1, index + 1) || dfs(r, c - 1, index + 1);
            board[r][c] = letter;
            return ok;
        };

        for (int r = 0; r < board.size(); r++){
            for (int c = 0; c < board[0].size(); c++){
                if (dfs(r, c, 0)) return true;
            }
        }
        return false;
    }
};
