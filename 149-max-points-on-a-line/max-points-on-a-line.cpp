class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) return n;
        int ans = 0;

        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> slopeCount;
            int duplicates = 0;
            int localMax = 0;

            for (int j = i + 1; j < n; ++j) {
                int dx = points[j][0] - points[i][0];
                int dy = points[j][1] - points[i][1];

                if (dx == 0 && dy == 0) {
                    duplicates++;
                    continue;
                }

                int g = gcd(dx, dy);
                dx /= g;
                dy /= g;

                // Normalize direction
                if (dx < 0) {
                    dx = -dx;
                    dy = -dy;
                } else if (dx == 0) {
                    dy = abs(dy);
                }

                slopeCount[{dy, dx}]++;
                localMax = max(localMax, slopeCount[{dy, dx}]);
            }

            ans = max(ans, localMax + duplicates + 1);
        }

        return ans;
    }
};