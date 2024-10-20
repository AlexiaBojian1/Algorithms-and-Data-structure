class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> sub;
        sub.push_back(nums[0]);
        for(int i = 1; i < nums.size(); i++){
            int num = nums[i];
            if(num > sub.back())
                sub.push_back(num);
            else {
                int j = binarySearch(sub, num);
                sub[j] = num;
            }
        }
        return sub.size();
    }
    int binarySearch(vector<int> sub, int num) {
        int l = 0, r = sub.size() - 1, mid = (l + r) / 2;
        while( l < r){
            mid = (l+r) / 2;
            if(num < sub[mid]) {
                r = mid;
            }
            else if(num > sub[mid]) {
                l = mid + 1;
            }
            else return mid;
        }
        return l;
    }
};