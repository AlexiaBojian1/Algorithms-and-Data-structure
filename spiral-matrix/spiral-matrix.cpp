class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        if(matrix.empty()) {
            return result;
        }
        
        int rows = matrix.size();
        int columns = matrix[0].size();
        int left = 0;
        int top = 0;
        int bottom = rows - 1;
        int right = columns - 1;
        
        while(result.size() < rows * columns) {
            for(int col = left; col <= right; col++) {
                result.push_back(matrix[top][col]);
            }
            
            for(int row = top + 1; row <= bottom; row++) {
                result.push_back(matrix[row][right]);
            }
            
            if(top != bottom) {
                for(int col = right - 1; col >= left; col--) {
                    result.push_back(matrix[bottom][col]);
                }
            }
            
            if(right != left) {
                for(int row = bottom - 1; row > top; row--) {
                    result.push_back(matrix[row][left]);
                }
            }
            
            left++;
            right--;
            top++;
            bottom--;
        }
        return result;
    }
};