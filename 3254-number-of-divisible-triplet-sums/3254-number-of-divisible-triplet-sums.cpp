class Solution {
public:
    int divisibleTripletCount(vector<int>& nums, int d) {
        if(nums.size() < 3) return 0;
        int output = 0;
        unordered_map<int, int> map;

        for(int i = 0; i < nums.size(); i++) {
            int need = (d - nums[i] % d) % d;
            output += map[need];

            for(int j = 0; j < i; j++) {
                map[(nums[i] + nums[j]) % d]++;
            }
        }
        return output;
    }
};