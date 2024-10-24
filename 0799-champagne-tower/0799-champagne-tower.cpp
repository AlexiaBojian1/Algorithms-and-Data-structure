class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double A[102][102] = {0.0};
        A[0][0] = (double)poured;
        for(int r = 0;r <= query_row;r++) {
            for(int c = 0; c <= r; c++) {
                double q = (A[r][c] -1.0)/2.0;
                if(q > 0) {
                    A[r+1][c] += q;
                    A[r+1][c+1] += q;
                }
            }
        }
        return min(1.0 , A[query_row][query_glass]);
    }
};