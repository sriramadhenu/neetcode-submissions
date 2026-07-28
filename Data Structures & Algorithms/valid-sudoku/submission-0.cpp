class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // each row must contain the digits 1-9 without duplicates
        for (vector v : board){
            unordered_map<char, int> m;
            for (char c : v){
                if (c == '.') continue;
                if (m.count(c) == 0) m[c]++;
                else return false;
            }
        }

        // each column must contain the digits 1-9 without duplicates
        for (int i = 0; i < board.size(); i++){
            unordered_map<char, int> m;
            for (int j = 0; j < board.size(); j++){
                char c = board[j][i];
                if (c == '.') continue;
                if (m.count(c) == 0) m[c]++;
                else return false;
            }
        }

        // each of the nine 3x3 sub-boxes of the grid must contain the digits 1-9 without duplicates
        for (int boxRow = 0; boxRow < 3; boxRow++){
            for (int boxCol = 0; boxCol < 3; boxCol++){
                unordered_map<char, int> m;
                for (int r = 0; r < 3; r++){
                    for (int c = 0; c < 3; c++){
                        char ch = board[boxRow * 3 + r][boxCol * 3 + c];
                        if (ch == '.') continue;
                        if (m.count(ch) == 0) m[ch]++;
                        else return false;
                    }
                }
            }
        }
        
        return true;
    }
};
