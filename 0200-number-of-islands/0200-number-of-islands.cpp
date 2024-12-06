class Solution {
public:
    int m ;
    int n;
    vector<pair<int,int>> directions=  {{0,1}, {1,0}, {-1,0}, {0,-1}};
    vector<vector<bool>> seen;
    vector<vector<char>> grid;
    int numIslands(vector<vector<char>>& grid) {

        this->grid = grid;
        n = grid.size();
         m = grid[0].size();
        seen = vector(n, vector<bool>(m, false));

        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m ;j++) {
                if(!seen[i][j] && grid[i][j] == '1') {
                    ans++;
                    seen[i][j] = true;
                    dfs(i,j);
                }
            }
        }

        return ans;
    }

    void dfs(int row, int col) {
        for( auto direction : directions) {
            int newrow = row + direction.first;
            int newcol = col + direction.second;
            if(valid(newrow, newcol) && !seen[newrow][newcol]) {
                seen[newrow][newcol] = true;
                dfs(newrow, newcol);
            }
        }
    }

    bool valid(int i, int j) {
        return 0<= i && i < n && 0 <= j && j < m && grid[i][j] == '1';
    }
};