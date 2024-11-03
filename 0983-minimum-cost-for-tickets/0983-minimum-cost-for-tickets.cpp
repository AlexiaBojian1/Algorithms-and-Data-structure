class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_set<int> travel_days(days.begin(), days.end()); 
        int last_day = days.back();
        vector<int> dp(last_day + 1, 0);     

        for (int day = 1; day <= last_day; day++) {
            if (travel_days.count(day) == 0) {
                dp[day] = dp[day - 1]; // No cost if we don’t need to travel on this day
            } else {
                // Calculate minimum cost by choosing each pass option
                int cost1 = dp[day - 1] + costs[0]; // 1-day pass
                int cost7 = dp[max(0, day - 7)] + costs[1]; // 7-day pass
                int cost30 = dp[max(0, day - 30)] + costs[2]; // 30-day pass
                dp[day] = min({cost1, cost7, cost30}); // Take the minimum of the three options
            }
        }

        return dp[last_day];   
    }
};