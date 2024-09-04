class Solution {
public:
    int k;
    int n;
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        this->k = k;
        this->n = n;
        vector<int> curr = {};
        backtrack(ans,1,  curr);
        return ans;
    }

    void backtrack(vector<vector<int>>& ans, int i,vector<int>& curr) {
        if(curr.size() == k) {
            ans.push_back(curr);
            return;
        }

        for(int j = i;j<=n;j++ ) {
            curr.push_back(j);
            backtrack(ans, j+1,curr);
            curr.pop_back();
        }
    }
};