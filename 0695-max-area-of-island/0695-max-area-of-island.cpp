class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<bool>> seen;
    int n;
    int m;
    vector<pair<int, int>> directions = {{0 , 1}, {1 , 0}, {0 , -1}, {-1 , 0}};
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        seen = vector(n, vector(m , false));
        int maxarea = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && !seen[i][j]) {
                    seen[i][j] = true;
                    maxarea = max(maxarea, dfs(i, j));
                    
                }
            }
        }
        return maxarea;
    }

    int dfs(int x, int y) {
        int area = 1;
        for(auto dir : directions) {
            int newx = x + dir.first;
            int newy = y + dir.second;
            if(valid(newx, newy) && !seen[newx][newy]) {
                seen[newx][newy] = true;
                area += dfs(newx, newy);
            }
        }
        return area;
    }

    bool valid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == 1;
    }
};