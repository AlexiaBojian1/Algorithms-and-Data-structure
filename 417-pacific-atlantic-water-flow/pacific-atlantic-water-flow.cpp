class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int rows;
    int cols;
    vector<vector<int>> heights;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        this->heights = heights;
        rows = heights.size();
        cols = heights[0].size();

        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));

        for(int i = 0; i < rows; i++) {
            dfs(i, 0, pacific);
            dfs(i, cols - 1, atlantic);
        }

        for(int j = 0; j < cols; j++) {
            dfs(0, j, pacific);
            dfs(rows - 1, j, atlantic);
        }

        vector<vector<int>> result;
        for(int r = 0; r < rows; r ++) {
            for(int c = 0; c < cols; c++) {
                if(pacific[r][c] && atlantic[r][c]) {
                    result.push_back({r,c});
                }
            }
        }

        return result;
    }

    void dfs(int r, int c, vector<vector<bool>>& reachable) {
        reachable[r][c] = true;

        for(auto& dir : directions) {
            int newrow = dir[0] + r;
            int newcol = dir[1] + c;

            if(newrow < 0 || newcol < 0 || newrow >= rows || newcol >= cols) continue;
            if(reachable[newrow][newcol]) continue;
            if (heights[newrow][newcol] < heights[r][c]) continue;
            dfs(newrow, newcol, reachable);
        }
    }
};