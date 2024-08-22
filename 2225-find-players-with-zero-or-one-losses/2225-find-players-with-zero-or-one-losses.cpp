class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
         unordered_map<int,int> counts;
        for(auto& match: matches) {
            int winner= match[0], loser=match[1];
            if(counts.find(winner)==counts.end()){
                counts[winner] = 0;
            }
            counts[loser]++;
        }

        vector<vector<int>> ans(2,vector<int>());
        for(auto[player,count]:counts) {
            if(count==0){
                ans[0].push_back(player);
            }
            if(count==1) {
                ans[1].push_back(player);
            }
        }
        sort(ans[0].begin(),ans[0].end());
        sort(ans[1].begin(),ans[1].end());
        return ans;
    }
};