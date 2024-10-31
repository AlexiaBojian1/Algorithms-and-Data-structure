class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long numsubarray = 0;
        for( auto num : nums) {
            if(num == 0) {
                numsubarray ++;
            } else{
                numsubarray = 0;
            }
            ans = ans + numsubarray;
        }
        return ans;
        
    }
};