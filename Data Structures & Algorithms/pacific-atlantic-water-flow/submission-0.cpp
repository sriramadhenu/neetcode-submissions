class Solution {
public:
    void dfs(int r, int c, vector<vector<bool>>& ocean, int prevHeight, vector<vector<int>>& heights){
        if (r < 0 || c < 0 || r >= heights.size() || c >= heights[0].size()) return;

        if (ocean[r][c] || heights[r][c] < prevHeight) return;

        ocean[r][c] = true;
        dfs(r + 1, c, ocean, heights[r][c], heights);
        dfs(r - 1, c, ocean, heights[r][c], heights);
        dfs(r, c + 1, ocean, heights[r][c], heights);
        dfs(r, c - 1, ocean, heights[r][c], heights);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answers;
        vector<vector<bool>> pacific(heights.size(), vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(), vector<bool>(heights[0].size(), false));


        for (int r = 0; r < heights.size(); r++){
            for (int c = 0; c < heights[r].size(); c++){
                if (r == 0 || c == 0) dfs(r, c, pacific, heights[r][c], heights);
                if (r == heights.size() - 1 || c == heights[r].size() - 1) dfs(r, c, atlantic, heights[r][c], heights);
            }
        }

        for (int i = 0; i < pacific.size(); i++){
            for (int j = 0; j < pacific[i].size(); j++){
                if (pacific[i][j] && atlantic[i][j]) answers.push_back({i, j});
            }
        }
        return answers;
    }
};
