class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> queue;
        vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
        int m , n;
        int freshCount = 0;
        n = grid.size();
        m = grid[0].size();
        for(int i = 0; i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(grid[i][j] == 2){
                    queue.push({i,j,0});
                } else if(grid[i][j] == 1) {
                    freshCount++;
                }
            }
        }

        int steps = 0;
        while(!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int row = curr[0];
            int col = curr[1];
            int step = curr[2];
            steps = max(steps, step);

            for(auto direction : directions) {
                int newrow = row + direction[0];
                int newcol = col + direction[1];

                if (newrow >= 0 && newrow < n && newcol >= 0 && newcol < m && grid[newrow][newcol] == 1) {
                    grid[newrow][newcol] = 2;
                    freshCount--;
                    queue.push({newrow, newcol, step+1});
                }
            }
        }
        return freshCount == 0 ? steps : -1;

    }
};