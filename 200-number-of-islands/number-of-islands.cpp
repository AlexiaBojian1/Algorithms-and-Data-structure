class Solution {
public:
    vector<pair<int, int>> directions = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> seen;
    vector<vector<char>> grid;
    int n;
    int m;
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        int ans = 0;
        seen = vector(n, vector(m , false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == '1' && !seen[i][j]) {
                    ans ++;
                    seen[i][j] = true;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }

    void dfs(int row, int col) {
        for(auto dir : directions) {
            int newrow = dir.first + row;
            int newcol = dir.second + col;
            if(valid(newrow, newcol)) {
                seen[newrow][newcol] = true;
                dfs(newrow, newcol);
            }
        }
    }

    bool valid(int row, int col) {
        return row >= 0 && col >= 0 && row < n && col < m && !seen[row][col] && grid[row][col] == '1';
    }
};