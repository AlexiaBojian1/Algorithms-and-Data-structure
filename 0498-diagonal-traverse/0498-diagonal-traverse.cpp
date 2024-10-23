class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        if(mat.empty() || mat[0].empty()) {
            return {};
        }

        int n = mat.size();
        int m = mat[0].size();
        int direction = 1;

        vector<int> result;
        result.reserve(n*m);

        int row = 0;
        int column = 0;

        while(row < n && column < m) {

            result.push_back(mat[row][column]);

            int newrow = row + (direction == 1 ? -1 : 1);
            int newcolumn = column + (direction == 1 ? 1 : -1);

            if(newrow < 0 || newrow == n || newcolumn < 0 || newcolumn == m ) {
                if(direction == 1) {
                    row = row + (column == m - 1 ? 1 : 0);
                    column = column + (column < m -1 ? 1 : 0);
                   
                } else {
                    column = column + (row == n - 1 ? 1 : 0);
                    row = row + (row < n - 1 ? 1 : 0);
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