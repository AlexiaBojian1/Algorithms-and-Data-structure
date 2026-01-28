class Solution {
public:
    vector<vector<int>> mat;
    vector<vector<int>> directions = {{0,1}, {-1,0}, {1,0}, {0,-1}};
    int m;
    int n;

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        this->mat = mat;
        n = mat.size();
        m = mat[0].size();
        queue<vector<int>> queue;
        vector<vector<bool>> seen = vector<vector<bool>>(n, vector<bool>(m , false));
        for(int i = 0; i < n;i++) {
            for(int j = 0; j< m; j++) {
                if(mat[i][j] == 0 && !seen[i][j]) {
                    seen[i][j] = true;
                    queue.push({i, j, 1});
                }
            }
        }

        while(!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int step = curr[2];
            for(auto dir : directions) {
                int newx = curr[0] + dir[0];
                int newy = curr[1] + dir[1];
                if(valid(newx, newy) && !seen[newx][newy]) {
                    seen[newx][newy] = true;
                    queue.push({newx, newy, step + 1});
                    mat[newx][newy] = step;
                }
            }
        }
        return mat;
    }

    bool valid(int row, int col) {
        return 0 <= row && row < n && 0 <= col && col < m ;
    }
};