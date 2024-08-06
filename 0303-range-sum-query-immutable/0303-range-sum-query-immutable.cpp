class NumArray {
public:
    vector<int> prefixsum;
    NumArray(vector<int>& nums) {
        prefixsum.push_back(nums[0]);
        for(int i= 1;i< nums.size();i++) {
            prefixsum.push_back(prefixsum.back() + nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        int ans = prefixsum[right];
        if(left-1 >= 0){
            ans = ans - prefixsum[left-1]; 
        }
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */