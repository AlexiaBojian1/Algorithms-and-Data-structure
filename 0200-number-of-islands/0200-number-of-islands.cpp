class Solution {
public:
    int m , n;
    vector<vector<char>> grid;
    vector<vector<bool>> seen;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        n = grid[0].size();
        m = grid.size();

        seen = vector(m , vector<bool>(n , false));
        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n ;j++) {
                if(grid[i][j] == '1' && !seen[i][j]) {
                    ans++;
                    seen[i][j] = true;
                    dfs(i,j);
                }
            }
        }
        return ans;
    }

    void dfs(int row , int col) {
        for(auto direction : directions) {
            int nextrow = row + direction[0];
            int nextcol = col + direction[1];
            if(valid(nextrow, nextcol) && !seen[nextrow][nextcol]) {
                seen[nextrow][nextcol] = true;
                dfs(nextrow, nextcol);
            }
        }
    }

    bool valid(int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n && grid[row][col] == '1';
    }
};