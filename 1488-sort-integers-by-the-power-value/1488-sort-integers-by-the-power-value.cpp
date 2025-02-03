class Solution {
public:
    unordered_map<long long, int> dp;
    int getpower (long long x) {
        if(x == 1) {
            return 0;
        }
        if(dp.count(x)) {
            return dp[x];
        }

        if(x % 2 == 0) {
            dp[x] = 1 + getpower(x/2);
        }
        if(x % 2 == 1) {
            dp[x] = getpower(3 * x + 1) + 1;
        }
        return dp[x];

    }
    int getKth(int lo, int hi, int k) {
        dp[1] = 0;
        vector<pair<int, int>> arr;
        for(int i = lo; i <= hi ; i++) {
            int power = getpower(i);
            arr.push_back({power, i});
        }

        sort(arr.begin(), arr.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first == b.first)
                return a.second < b.second;
            return a.first < b.first;
        });

        return arr[k-1].second;
    }
};