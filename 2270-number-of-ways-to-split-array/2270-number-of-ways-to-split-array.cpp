class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size();

        vector<long> prefix = {nums[0]};

        for(int i = 1; i < n;i++) {
            prefix.push_back(prefix.back() + nums[i]);
        }

        int ans = 0;
        for(int i = 0;i < n-1;i++) {
            long leftsection = prefix[i];
            long rightsection  = prefix.back() - prefix[i];
            if(leftsection >= rightsection){
                ans++;
            }
        }
        return ans;
    }
};