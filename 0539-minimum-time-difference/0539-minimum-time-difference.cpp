class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes(timePoints.size(), 0);
        int i = 0;
        for(auto timePoint : timePoints) {
            int h = stoi(timePoint.substr(0,2));
            int m = stoi(timePoint.substr(3));
            minutes[i] = 60 * h + m;
            i++;
        }

        int ans = INT_MAX;
        sort(minutes.begin(), minutes.end());
        for(int i = 0; i < timePoints.size() - 1; i++) {
            ans = min(ans, minutes[i + 1] - minutes[i]);
        }

        return min(ans, 24 * 60 - minutes[timePoints.size() - 1] + minutes[0]);

    }
};