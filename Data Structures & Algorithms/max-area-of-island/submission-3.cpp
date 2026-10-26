class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;

        function<int(int, int)> dfs = [&](int row, int col) -> int {
            if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) return 0;
            grid[row][col] = 0;
            return 1 + dfs(row + 1, col) + dfs(row, col + 1) + dfs(row - 1, col) + dfs(row, col - 1);
        };

        for (int r = 0; r < grid.size(); r++){
            for (int c = 0; c < grid[0].size(); c++){
                if (grid[r][c] == 1){
                    maxArea = max(maxArea, dfs(r, c));
                }
            }
        }
        return maxArea;
    }
};
