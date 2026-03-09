class Solution {
public:
    
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> queue;
        vector<vector<int>> directions = {{0,1}, {1,0}, {0, -1}, {-1,0}};
        int n = grid.size();
        int m = grid[0].size();
        int freshcount = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j ++) {
                if(grid[i][j] == 2) {
                    queue.push({i, j, 0});
                } else if(grid[i][j] == 1) {
                    freshcount++;
                }
            }
        } 
        int steps = 0;
        while(!queue.empty()) {
            auto current = queue.front();
            queue.pop();
            int step = current[2];
            int row = current[0];
            int col = current[1];
            steps = max(steps, step);
            for(auto dir : directions) {
                int newrow = row + dir[0];
                int newcol = col + dir[1];
                if(newrow >= 0 && newcol >= 0 && newrow < n && newcol < m && grid[newrow][newcol] == 1) {
                    queue.push({newrow, newcol, step + 1});
                    grid[newrow][newcol] = 2;
                    freshcount--;
                }
            }
        }
        return freshcount == 0 ? steps : -1;
    }
};