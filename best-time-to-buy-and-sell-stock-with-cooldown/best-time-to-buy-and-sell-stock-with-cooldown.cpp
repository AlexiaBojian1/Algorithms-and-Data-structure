class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        int n = prices.size();
        vector<int> buy(n, 0), sell(n, 0), cooldown(n, 0);

        // Initial conditions
        buy[0] = -prices[0];
        sell[0] = 0;
        cooldown[0] = 0;

        for (int i = 1; i < n; ++i) {
            // Maximum profit on day `i` if we buy: either continue holding from previous buy, or cooldown and buy today
            buy[i] = max(buy[i - 1], cooldown[i - 1] - prices[i]);
            // Maximum profit on day `i` if we sell: can only sell if we bought before
            sell[i] = buy[i - 1] + prices[i];
            // Maximum profit on day `i` if we cooldown: can either continue cooldown from previous day or transition from sell
            cooldown[i] = max(cooldown[i - 1], sell[i - 1]);
        }

        // The answer will be the max profit on the last day if we either sold or were in cooldown (cannot end on a buy)
        return max(sell[n - 1], cooldown[n - 1]);
        
    }
};