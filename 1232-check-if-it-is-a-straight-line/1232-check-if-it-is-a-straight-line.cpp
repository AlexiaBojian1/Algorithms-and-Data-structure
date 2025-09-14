class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];

        int dx = x2 - x1;
        int dy = y2 - y1;

        for(int i = 2; i < coordinates.size(); i++) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            if((x - x1) * dy != (y - y1) * dx) {
                return false;
            }
        }
        return true;
    }
};