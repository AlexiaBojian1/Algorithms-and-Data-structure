class Solution {
public:
    vector<vector<int>> grid;
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1},{1,1},{-1,-1},{-1,1},{1,-1}};
    int n;
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) {
            return -1;
        }
        this->grid = grid;
        n = (int)(grid.size());
        vector<vector<bool>> seen(n, vector<bool>(n, false));
        queue<vector<int>> queue;
        queue.push({0,0,1});
        seen[0][0] = true;

        while(!queue.empty()) {
            vector<int> curr;
            curr = queue.front();
            queue.pop();
            int row = curr[0];
            int col = curr[1];
            int step = curr[2];
            if(row == n - 1 && col == n-1) {
                return step;
            }

            for(auto direction : directions) {
                int newrow = row + direction[0];
                int newcol = col + direction[1];
                if(valid(newrow, newcol) && !seen[newrow][newcol]) {
                    seen[newrow][newcol] = true;
                    queue.push({newrow, newcol, step+1});
                }
            }
        }
        return -1;
    }

    bool valid(int r, int c) {
        return 0<=r && r < n && 0<= c && c < n && grid[r][c] == 0;
    }
};