class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> nums;
        vector<int> factorials(n);
        factorials[0] = 1;
        nums.push_back('1');

        for(int i = 1; i < n; i++) {
            factorials[i] = factorials[i - 1] * i;
            nums.push_back(i + 1 + '0');
        }

        k--;

        string result = "";

        for(int i = n - 1; i > -1; --i) {
            int idx = k / factorials[i];
            k -= idx * factorials[i];
            result += nums[idx];
            nums.erase(nums.begin() + idx);
        }

        return result;
    }
};