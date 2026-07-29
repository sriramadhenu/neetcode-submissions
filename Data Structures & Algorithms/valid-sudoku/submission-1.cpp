class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<char>> rows(9);
        vector<unordered_set<char>> cols(9);
        vector<unordered_set<char>> squares(9);

        for (int r = 0; r < board.size(); r++){
            for (int c = 0; c < board.size(); c++){
                char cur = board[r][c];
                if (cur == '.') continue;

                int square = (r / 3) * 3 + (c / 3);
                if (rows[r].contains(cur) || cols[c].contains(cur) || squares[square].contains(cur)) return false;
                rows[r].insert(cur);
                cols[c].insert(cur);
                squares[square].insert(cur);
            }
        }
        return true;
    }
};
