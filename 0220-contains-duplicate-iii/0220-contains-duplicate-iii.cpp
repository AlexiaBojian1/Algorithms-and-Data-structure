class Solution {
public:
    long getId(long x, long w) {return x < 0 ? (x + 1) / w - 1 : x / w;}
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        if(valueDiff < 0) return false;

        unordered_map<long, long> buckets;
        long w = (long)valueDiff + 1;
        for(int i = 0; i < nums.size(); i ++) {
            long bucket = getId(nums[i], w);

            if(buckets.count(bucket)) return true;
            if(buckets.count(bucket - 1) && abs(nums[i] - buckets[bucket - 1]) < w) return true;
            if(buckets.count(bucket + 1) && abs(nums[i] - buckets[bucket + 1]) < w) return true;

            buckets[bucket] = (long)nums[i];

            if (i >= indexDiff) {
                buckets.erase(getId(nums[i - indexDiff], w));
            }
        } 
        return false;
    }
};