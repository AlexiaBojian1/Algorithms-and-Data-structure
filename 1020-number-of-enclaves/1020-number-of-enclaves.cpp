class Solution {
public:
    vector<vector<int>> grid;
    int n;
    int m;
    vector<vector<bool>> seen;
    vector<pair<int, int>> directions = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};

    int numEnclaves(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        seen = vector(n, vector(m , false));
        for(int i = 0; i < n; i++) {
            if(grid[i][0] == 1 && !seen[i][0]) {
                seen[i][0] = true;
                dfs(i, 0);
            }
            if(grid[i][m - 1] == 1 && !seen[i][m - 1]) {
                seen[i][m - 1] = true;
                dfs(i, m - 1);
            }
        } 
        for(int j = 0; j < m; j++) {
            if(grid[0][j] == 1 && !seen[0][j]) {
                seen[0][j] = true;
                dfs(0, j);
            }
            if(grid[n - 1][j] == 1 && !seen[n - 1][j]) {
                seen[n - 1][j] = true;
                dfs(n - 1, j);
            }
        }   

        for(int i = 0 ; i < n ;i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !seen[i][j]) {
                    ans++;
                }
            }
        }

        return ans;
    }

    void dfs(int row, int col) {
        for(auto dir : directions) {
            int newrow = dir.first + row;
            int newcol = dir.second + col;
            if(valid(newrow, newcol) && grid[newrow][newcol] == 1) {
                seen[newrow][newcol] = true;
                dfs(newrow, newcol);
            }
        }
    }

    bool valid(int row, int col) {
        return row >=0 && col >= 0 && row < n && col < m && !seen[row][col];
    }
};