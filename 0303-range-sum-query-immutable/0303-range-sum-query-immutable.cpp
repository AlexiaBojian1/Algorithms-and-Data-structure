class NumArray {
public:
    vector<int> prefixSum;
    NumArray(vector<int>& nums) {
        int count = 0;
        for(int num : nums) {
            count = count + num;
            prefixSum.push_back(count);
        }
    }
    
    int sumRange(int left, int right) {
        int ans = prefixSum[right];
        if(left - 1 >= 0) {
            ans = ans - prefixSum[left - 1];
        }

        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */