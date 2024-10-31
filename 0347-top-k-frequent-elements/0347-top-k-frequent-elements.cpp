class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        unordered_map<int,int> mp;
        for(int num : nums) {
            mp[num]++;
        }

        vector<vector<int>> buckets(n+1);
        for(auto i:mp) {
            buckets[i.second].push_back(i.first);
        }
        vector<int> result;
        
        for (int i = n; i >= 0; i--) {
            if (result.size() >= k) {
                break;
            }
            if (!buckets[i].empty()) {
                result.insert(result.end(), buckets[i].begin(), buckets[i].end());
            }
        }
        
        return result;
    }
};