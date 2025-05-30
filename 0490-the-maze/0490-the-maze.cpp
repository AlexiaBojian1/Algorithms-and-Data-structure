class Solution {
public:
    vector<vector<int>> maze;
    vector<vector<int>> directions = {{0,1},{1, 0}, {-1,0}, {0,-1}};
    int n;
    int m;
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        this->maze = maze;
        this->n = maze.size();
        this->m = maze[0].size();
        vector<vector<bool>> seen(n, vector<bool>(m , false));
        queue<vector<int>> queue;
        queue.push({start[0], start[1]});
        seen[start[0]][start[1]] = true;

        while(!queue.empty()) {
            vector<int> curr;
            curr = queue.front();
            queue.pop();
            if(curr[0] == destination[0] && curr[1] == destination[1]) {
                return true;
            }

            for(auto direction : directions) {
                int row = curr[0];
                int col = curr[1];

                // Roll the ball until it hits a wall
                while (valid(row + direction[0], col + direction[1])) {
                    row += direction[0];
                    col += direction[1];
                }
                if (!seen[row][col]) {
                    seen[row][col] = true;
                    queue.push({row, col});
                }
            }
        }
        return false;
    }

    bool valid(int row, int col) {
        return row >= 0 && row < n && col >=0 && col < m && maze[row][col] == 0;
    }

};