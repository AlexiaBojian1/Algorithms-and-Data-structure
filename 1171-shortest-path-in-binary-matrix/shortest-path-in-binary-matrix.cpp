class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    int n;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        this->grid = grid;
        n = grid.size();
        if(grid[0][0] == 1) return -1;
        vector<vector<bool>> seen = vector<vector<bool>>(n, vector<bool>(n, false));
        queue<vector<int>> queue;
        queue.push({0, 0, 1});
        seen[0][0] = true;
        while(!queue.empty()) {
            vector<int> curr;
            curr = queue.front();
            queue.pop();
            int step = curr[2];
            int x = curr[0];
            int y = curr[1];
            if(curr[0] == n - 1 && curr[1] == n - 1) return step;
            for(auto dir: directions) {
                int newx = x + dir[0];
                int newy = y + dir[1];
                if(valid(newx, newy)  && !seen[newx][newy]) {
                    seen[newx][newy] = true;
                    queue.push({newx, newy, step + 1});
                }

            }
        }
        return -1;
    }
    bool valid(int r, int c) {
        return 0<=r && r < n && 0<= c && c < n && grid[r][c] == 0;
    }
};