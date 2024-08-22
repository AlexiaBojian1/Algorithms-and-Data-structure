class Solution {
public:
    int largestUniqueNumber(vector<int>& nums) {
        int maxi=-1;
        unordered_map<int,int> counts;
        for(int num: nums){
            counts[num]++;
        }
        for(int num:nums){
            if(counts[num]==1){
                if(num>maxi)
                    maxi=num;
            }
        }
        return maxi;
    }
};