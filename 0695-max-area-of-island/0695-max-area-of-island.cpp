class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{1,0}, {0,1} , {-1,0},{0,-1}};
    int m;
    int n;
    vector<vector<bool>> seen;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int current = 0;
        int maxarea = 0;
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        seen = vector(n, vector<bool>(m , false));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!seen[i][j] && grid[i][j] == 1) {
                    seen[i][j] = true;
                    current = dfs(i,j);
                    maxarea = max(maxarea, current);
                }
            }
        }
        return maxarea;
    }

    int dfs(int i, int j) {
        int area = 1;
        for(auto direction : directions) {
            int newi = direction[0] + i;
            int newj = direction[1] + j;
            if( valid(newi, newj) && !seen[newi][newj]) {
                seen[newi][newj] = true;
                 area += dfs(newi, newj);
            }
        }
        return area;
    }
     bool valid(int i, int j) {
        return 0<=i && i <n && 0 <=j && j < m && grid[i][j] == 1;
    }
};