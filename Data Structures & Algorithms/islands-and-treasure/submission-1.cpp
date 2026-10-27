class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int r = 0; r < grid.size(); r++){
            for (int c = 0; c < grid[0].size(); c++){
                if (grid[r][c] == 0) q.push({r, c});
            }
        }

        while (!q.empty()){
            auto [row, col] = q.front();
            q.pop();

            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            for (int i = 0; i < 4; i++){
                int nr = row + dr[i], nc = col + dc[i];
                if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 2147483647){
                    grid[nr][nc] = grid[row][col] + 1;
                    q.push({nr, nc});
                }
            }
        }
    }
};
