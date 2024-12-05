class Solution {
public:
    int m,n;
    vector<vector<int>> grid;
    vector<vector<bool>> seen;
    vector<vector<int>> directions = {{1,0},{-1,0},{0,1},{0,-1}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();
        seen = vector(m, vector<bool>(n,false));
        int maxarea = 0;
        for(int i=0;i<m;i++) {
            for(int j = 0;j<n;j++) {
                if(!seen[i][j] && grid[i][j] ==1){
                    seen[i][j] = true;
                    int currarea = dfs(i,j);
                    maxarea = max(maxarea,currarea);
                }
            }
        }
        return maxarea;
    }

    int dfs(int row, int col){
        int area = 1;
        for(vector<int> direction : directions) {
            int nextcol = col + direction[1];
            int nextrow = row+ direction[0];
            if(valid(nextrow,nextcol) && !seen[nextrow][nextcol]) {
                seen[nextrow][nextcol] = true;
                area = area+ dfs(nextrow, nextcol);
            }
        }
        return area;
    }
    bool valid(int row, int col) {
        return 0<=row && row < m && 0<=col && col < n && grid[row][col] ==1;
    }
};