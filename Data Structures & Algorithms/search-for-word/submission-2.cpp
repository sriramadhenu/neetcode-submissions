class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool found = false;

        function<bool(int, int, int)> dfs = [&](int row, int col, int index){
            if (index == word.size()) return true;
            if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()) return false;
        
            char letter = board[row][col];
            if (letter != word[index]) return false;
            board[row][col] = '#';

            bool ok = dfs(row + 1, col, index + 1) || dfs(row - 1, col, index + 1) ||  dfs(row, col + 1, index + 1) || dfs(row, col - 1, index + 1);
            board[row][col] = letter;
            return ok;
        };

        for (int r = 0; r < board.size(); r++){
            for (int c = 0; c < board[r].size(); c++){
                if (dfs(r, c, 0)) return true;
            }
        }
        return false;
    }
};
