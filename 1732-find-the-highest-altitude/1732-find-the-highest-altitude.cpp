class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int> prefix = {0};
        int maxi = prefix.back();
        for(int i=0;i<gain.size();i++) {
            prefix.push_back(prefix.back() + gain[i]);
            maxi = max(maxi, prefix.back());
        }
        return maxi;
    }
};