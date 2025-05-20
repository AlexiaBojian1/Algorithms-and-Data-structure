class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int answer = 0;
        for(int num : nums) {
            freq[num]++;
        }

        for(int num : nums) {
            int partner = k - num;
            if(freq[partner] > 0 && freq[num] > 0) {
                if(partner != num || freq[num] > 1){
                answer++;
                freq[num] --;
                freq[partner] --;
                }
            }    
        }
        return answer;
    }
};