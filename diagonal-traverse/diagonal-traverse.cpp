class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) {
            return{};
        }
        
        int n = matrix.size();
        int m = matrix[0].size();
        
        int row = 0;
        int column = 0;
        
        int direction = 1;
        
        vector<int> result;
        result.reserve(n*m);
        
        while(row < n && column < m) {
            result.push_back(matrix[row][column]);
            
            int newrow = row + (direction == 1 ? -1 : 1);
            int newcolumn = column + (direction == 1 ? 1 : -1);
            
            if(newrow < 0 || newrow == n || newcolumn < 0 || newcolumn == m) {
                if(direction == 1) {
                    row += (column == m - 1 ? 1 : 0);
                    column += (column < m - 1 ? 1:0);
                } else {
                    column += (row == n - 1 ? 1 : 0);
                    row += (row < n - 1 ? 1 : 0);
                }
                
                direction = 1 - direction;
            } else {
                row = newrow;
                column = newcolumn;
            }
        }
        return result;
    }
};