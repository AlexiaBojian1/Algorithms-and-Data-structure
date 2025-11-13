class Solution {
public:
    vector<vector<char>> grid;
    vector<vector<bool>> seen;
    int m;
    int n;
    vector<pair<int, int>> directions =  {{0,1}, {1,0}, {-1,0}, {0,-1}};
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        seen = vector(n, vector<bool>(m , false));

        int ans = 0;
        for(int i = 0;i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!seen[i][j] && grid[i][j] == '1') {
                    ans ++;
                    seen[i][j] = true;
                    dfs(i, j);
                }
            }
        }
        return ans;
    }

    void dfs(int i, int j) {
        for(auto direct : directions) {
            int newi = i + direct.first;
            int newj = j + direct.second;
            if(valid(newi, newj) && !seen[newi][newj]) {
                seen[newi][newj] = true;
                dfs(newi, newj);
            }
        }
    }

     bool valid(int i, int j) {
        return i >= 0 && i < n && j >= 0 && j < m && grid[i][j] == '1';
    }
};