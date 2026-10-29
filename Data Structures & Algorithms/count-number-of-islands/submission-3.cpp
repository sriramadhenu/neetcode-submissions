class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int answer = 0;
        int rows = grid.size(), cols = grid[0].size();

        function<void(int, int)> dfs = [&] (int r, int c){
            if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') return;
            
            grid[r][c] = '0';
            dfs(r + 1, c);
            dfs(r, c + 1);
            dfs(r - 1, c);
            dfs(r, c - 1);
        };

        for (int r = 0; r < rows; r++){
            for (int c = 0; c < cols; c++){
                if (grid[r][c] == '1'){
                    answer++;
                    dfs(r, c);
                }
            }
        }
        return answer;
    }
};
