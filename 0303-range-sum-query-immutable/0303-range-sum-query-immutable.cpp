class NumArray {
public:
    vector<int> prefixsum;
    NumArray(vector<int>& nums) {
        int count = 0;
        for(int num:nums) {
            count = count+ num;
            prefixsum.push_back(count);
        }
    }
    
    int sumRange(int left, int right) {
        int ans = prefixsum[right];
        if(left -1>=0) {
            ans = ans-prefixsum[left-1];
        }
        return ans;
    }
};