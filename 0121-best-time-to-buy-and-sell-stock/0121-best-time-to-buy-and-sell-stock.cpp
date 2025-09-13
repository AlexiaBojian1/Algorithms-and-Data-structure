class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int min = INT_MAX;
        for(auto price : prices) {
            if(price < min) min = price;
            if(price - min > result) result = price - min;
        }
        return result;
    }
};