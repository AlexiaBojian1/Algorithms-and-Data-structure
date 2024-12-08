class Solution {
public:
    vector<vector<int>> directions = {{1,0},{0,1},{-1,0},{0,-1}};
    int n , m;
    vector<vector<char>> maze;
    vector<int> entrance ;
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
         n = maze.size();
         m = maze[0].size();
        this->maze = maze;
        this->entrance = entrance;
        
        queue<vector<int>> queue;
        vector<vector<bool>> seen (n, vector<bool>(m , false));
        
        queue.push({entrance[0], entrance[1], 0});
        seen[entrance[0]][entrance[1]] = true;
        
        while(!queue.empty()) {
            vector<int> curr = queue.front();
            queue.pop();
            int x = curr[0];
            int y = curr[1];
            int step = curr[2];
            if ((x != entrance[0] || y != entrance[1]) && 
                (x == 0 || x == n-1 || y == 0 || y == m-1)) {
                return step;
            }
            
            for(auto direction : directions) {
                int nextrow = x + direction[0];
                int nextcol = y + direction[1];
                if(valid(nextrow, nextcol) && !seen[nextrow][nextcol]) {
                    queue.push({nextrow, nextcol, step + 1});
                    seen[nextrow][nextcol] = true;
                }
            }
        }
        return -1;
    }
    
    bool valid(int r , int c) {
        return 0<= r && r < n && 0 <= c && c < m && maze[r][c] == '.' && !(r == entrance[0] && c == entrance[1]);
    }
};