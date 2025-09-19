class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int n = prices.size();
        vector<int> buy(n, 0), sell(n, 0), cooldown(n, 0);
        buy[0] = -prices[0];
        sell[0] = 0;
        cooldown[0] = 0;

        for(int i = 1; i < n; i++) {
            buy[i] = max(buy[i - 1], cooldown[i - 1] - prices[i]);
            sell[i] = buy[i - 1] + prices[i];
            cooldown[i] = max(cooldown[i - 1], sell[i - 1]);
        }

        return max(sell[n - 1], cooldown[n - 1]);
    }
};