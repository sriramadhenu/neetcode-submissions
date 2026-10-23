class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int count = 0;

        function<void(int, int)> dfs = [&](int row, int col){
            if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] != '1') return;

            grid[row][col] = '0';
            dfs(row + 1, col);
            dfs(row - 1, col);
            dfs(row, col + 1);
            dfs(row, col - 1);
        };

        for (int r = 0; r < grid.size(); r++){
            for (int c = 0; c < grid[0].size(); c++){
                if (grid[r][c] == '1'){
                    count++;
                    dfs(r, c);
                }
            }
        }

        return count;
    }
};
