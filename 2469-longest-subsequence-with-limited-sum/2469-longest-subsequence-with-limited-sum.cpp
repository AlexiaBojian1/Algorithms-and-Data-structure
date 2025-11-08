class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(), nums.end());

        // build prefix sums in 64-bit to avoid overflow
        vector<long long> pref(nums.size());
        long long s = 0;
        for (int i = 0; i < (int)nums.size(); ++i) {
            s += nums[i];
            pref[i] = s;
        }

        vector<int> ans;
        ans.reserve(queries.size());
        for (int q : queries) {
            int k = upper_bound_manual(pref, (long long)q); // count of prefix <= q
            ans.push_back(k);
        }
        return ans;
    }

private:
    // Return first index i such that a[i] > x  (i.e., size of {a[i] <= x})
    // Half-open interval binary search on [l, r)
    static int upper_bound_manual(const vector<long long>& a, long long x) {
        int l = 0, r = (int)a.size();       // search in [l, r)
        while (l < r) {
            int m = l + (r - l) / 2;
            if (a[m] <= x) l = m + 1;       // drop [l, m]
            else r = m;                     // keep [l, m)
        }
        return l;                           // number of elements <= x
    }
};
