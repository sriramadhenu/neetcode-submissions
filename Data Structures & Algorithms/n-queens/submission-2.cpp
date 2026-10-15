class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));

        vector<bool> cols(n, false);
        vector<bool> diag(n * 2, false);
        vector<bool> antidiag(n * 2, false);

        function<void(int)> dfs = [&](int row){
            if (row == n){
                result.push_back(board);
                return;
            }

            for (int col = 0; col < n; col++){
                if (cols[col] || diag[row - col + n] || antidiag[row + col]) continue;
                board[row][col] = 'Q';
                cols[col] = true;
                diag[row - col + n] = true;
                antidiag[row + col] = true;

                dfs(row + 1);

                board[row][col] = '.';
                cols[col] = false;
                diag[row - col + n] = false;
                antidiag[row + col] = false;
            }

        };

        dfs(0);
        return result;
    }
};
