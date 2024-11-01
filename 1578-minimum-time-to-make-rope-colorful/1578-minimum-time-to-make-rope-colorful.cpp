class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totaltime = 0;
        int i = 0;
        int j = 0;

        while( i < neededTime.size() && j < neededTime.size()) {
            int currtotal = 0;
            int currmax = 0;

            while(j < neededTime.size() && colors[i] == colors[j]) {
                currtotal += neededTime[j];
                currmax = max(currmax, neededTime[j]);
                j++;
            }

            totaltime += currtotal - currmax;
            i = j;
        }
        return totaltime;
    }
};