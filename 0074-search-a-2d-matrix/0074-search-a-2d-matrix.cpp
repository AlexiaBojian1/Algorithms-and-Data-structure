class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = int(matrix[0].size()); //number of columns
        int m = int(matrix.size()); // number of rows
        int left = 0;
        int right = n * m  - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            int row = mid / n;
            int col = mid % n;
            int num = matrix[row][col];
            if(target == num) {
                return true;
            } 
            if(num < target) {
                left = mid + 1;
            } else if( num > target){
                right = mid - 1;
            }
        }
        return false;
    }
};