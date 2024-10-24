class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.push_back({1});// first row
        for(int i = 1;i< numRows;i++) {
            vector<int> row;
            vector<int>& prevrow = triangle[i-1];
            row.push_back(1);
            for(int j=1;j<i;j++) {
                row.push_back(prevrow[j]+prevrow[j-1]);
            }
            row.push_back(1);
            triangle.push_back(row);
        }
        return triangle;
    }
};