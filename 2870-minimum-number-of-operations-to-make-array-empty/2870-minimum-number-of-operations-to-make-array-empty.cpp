class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums) {
            freq[num]++;
        }
        int ans = 0;
        for(auto [_,c] : freq) {
            if(c == 1) {
                return -1;
            }
            ans += ceil((double)(c)/3);
        }
        return ans;
    }
};