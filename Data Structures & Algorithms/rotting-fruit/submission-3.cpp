class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fruit_count = 0;
        for (int r = 0; r < grid.size(); r++){
            for (int c = 0; c < grid[r].size(); c++){
                if (grid[r][c] == 2) q.push({r, c});
                else if (grid[r][c] == 1) fruit_count++;
            }
        }
        if (fruit_count == 0) return 0;

        int minutes = 0;
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, -1, 0, 1};
        while (!q.empty()){
            int level = q.size();
            bool rotted = false;
            for (int i = 0; i < level; i++){
                auto [row, col] = q.front();
                q.pop();

                for (int d = 0; d < 4; d++){
                    int nr = row + dr[d], nc = col + dc[d];
                    if (nr >= 0 && nc >= 0 && nr < grid.size() && 
                    nc < grid[0].size() && grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fruit_count--;
                        q.push({nr, nc});
                        rotted = true;
                    }
                }
            }
            if (rotted) minutes++;
        }
        return (fruit_count == 0) ? minutes : -1;
    }
};
