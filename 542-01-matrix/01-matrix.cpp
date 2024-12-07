class Solution {
public:
    int m;
    int n;
    vector<vector<int>> mat;
    vector<vector<int>> directions = {{0,1},{1,0},{-1,0},{0,-1}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        this->mat = mat;
        n = mat.size();
        m = mat[0].size();

        queue<vector<int>> queue;
        vector<vector<bool>> seen (n, vector<bool>(m, false));

        for(int row = 0 ; row < n ;row++) {
            for(int col = 0; col < m; col++) {
                if(mat[row][col] == 0) {
                    queue.push({row,col,1});
                    seen[row][col] = true;
                }
            }
        }

        while(!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int row = curr[0];
            int col = curr[1];
            int step = curr[2];
            for(auto direction : directions) {
                int newrow = row + direction[0];
                int newcol = col + direction[1];
                if(valid(newrow, newcol) && !seen[newrow][newcol]) {
                    seen[newrow][newcol] = true;
                    //mat[newrow][newcol] = step;
                    queue.push({newrow, newcol, step + 1});
                    mat[newrow][newcol] = step;
                }
            }
        }
        return mat;
    }

    bool valid(int row, int col) {
        return 0 <= row && row < n && 0 <= col && col < m && mat[row][col] == 1;
    }
};