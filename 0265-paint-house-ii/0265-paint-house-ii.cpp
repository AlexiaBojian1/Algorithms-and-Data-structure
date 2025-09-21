class Solution {
public:
    //[0][1], [0][2] .. -> house 0
    //costs[1][2] -> house 1 color 2
    int minCostII(vector<vector<int>>& costs) {
        if(costs.size() == 0) return 0;
        int n = costs.size();
        int k = costs[0].size();
        if(k == 0) return 0;

        vector<int> dp = costs[0];

        for(int i = 1; i < n; i++) {
            int min1 = -1;
            int min2 = -2;
            for(int c = 0; c < k; c++){
                if(min1 == -1 || dp[c] < dp[min1]) {
                    min2 = min1;
                    min1 = c;
                } else if(min2 == -1 || dp[c] < dp[min2]) {
                    min2 = c;
                }
            }

            vector<int> ndp(k);
            for(int c = 0; c < k; c++) {
                int bestprev = ( c == min1) ? dp[min2] : dp[min1];
                ndp[c] = costs[i][c] + bestprev;
            }
            dp.swap(ndp);
        }
        return *std::min_element(dp.begin(), dp.end());
    }
};