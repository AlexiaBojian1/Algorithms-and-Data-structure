class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;
        int m = potions.size();
        for(auto spell : spells) {
            long long minPotion = (success + spell - 1) / spell; // Ceiling division
            int k = binarySearch(potions, minPotion);
            ans.push_back(m - k);
        }

        return ans;
    }

    int binarySearch(vector<int>& potions, double target) {
        int left = 0;
        int right = potions.size()  ;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(potions[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};