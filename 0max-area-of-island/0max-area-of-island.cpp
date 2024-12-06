class Solution {
public:
    int m ;
    int n;
    vector<vector<int>> directions = {{1,0}, {0,1} , {-1,0},{0,-1}};
    vector<vector<bool>> seen;
    vector<vector<int>> grid;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        this->grid = grid;
         n = grid.size();
         m = grid[0].size();
        
        int maxarea = 0;
        seen = vector(n, vector<bool>(m, false));
        
        for(int i = 0; i < n;i++) {
            for(int j = 0;j < m;j++) {
                if(!seen[i][j] && grid[i][j] == 1) {
                    seen[i][j] = true;
                    maxarea = max(maxarea, dfs(i,j));
                }
            }
        }
        return maxarea;
    }
    
    int dfs(int i, int j) {
        int area = 1;
        for(auto direction : directions) {
            int newrow = i + direction[0];
            int newcol = j + direction[1];
            if(valid(newrow, newcol) && !seen[newrow][newcol]){
                seen[newrow][newcol] = true;
                area += dfs(newrow,newcol);
            }
        }
        return area;
    }
    
    bool valid(int i, int j) {
        return 0<=i && i <n && 0 <=j && j < m && grid[i][j] == 1;
    }
};