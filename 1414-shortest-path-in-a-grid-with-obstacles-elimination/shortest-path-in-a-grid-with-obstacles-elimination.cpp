class Solution {
public:
    int m, n;
    vector<vector<int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    int shortestPath(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        queue<vector<int>> queue;
        queue.push ({0, 0, k, 0});

        vector<vector<int>> seen(m, vector<int>(n, -1));

        while (!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();

            int row = curr[0];
            int col = curr[1];
            int remain = curr[2];
            int step = curr[3];

            if (row == m - 1 && col == n - 1) {
                return step;
            }

            if (grid[row][col] == 1) {
                if (remain == 0) {
                    continue;
                } else {
                    remain--;
                }
            }

            if (seen[row][col] >= remain) {
                continue;
            }

            seen[row][col] = remain;
            for (auto direction : directions) {
                int nextrow = row + direction[0];
                int nextcol = col + direction[1];
                if (valid(nextrow, nextcol)) {
                    queue.push({nextrow, nextcol, remain, step+1});
                }
            }
        }
        return -1;
    }

     bool valid(int row, int col) {
        return 0 <= row && row < m && 0 <= col && col < n;
    }
};