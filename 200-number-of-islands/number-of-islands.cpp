class Solution {
public:
    vector<vector<char>> grid;
    int m;
    int n;
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<bool>> seen;
    int numIslands(vector<vector<char>>& grid) {
        this->grid = grid;
        n = grid.size();
        m = grid[0].size();
        seen = vector(n, vector(m , false));
        int ans = 0;
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

    // void dfs(int x, int y) {
    //     for(auto dir : directions) {
    //         int newx = x + dir.first;
    //         int newy = y + dir.second;
    //         if(valid(newx, newy) && !seen[newx][newy]) {
    //             seen[newx][newy] = true;
    //             dfs(newx, newy);
    //         }
    //     }
    // }

    void dfs(int x, int y) {
        stack<pair<int, int>> stack;
        stack.push(pair(x, y));

        while(!stack.empty()) {
            auto[row, col] = stack.top();
            stack.pop();
            for(auto dir : directions) {
                int newx = row + dir.first;
                int newy = col + dir.second;
                if(valid(newx, newy) && !seen[newx][newy]) {
                    seen[newx][newy] = true;
                    stack.push(pair(newx, newy));
                }
            }
        }
    }

    bool valid(int x, int y) {
        return x >= 0 && y >= 0 && x < n && y < m && grid[x][y] == '1';
    }
};