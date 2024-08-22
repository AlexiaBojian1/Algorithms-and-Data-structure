class Solution {
public:
    int countElements(vector<int>& arr) {
        unordered_set<int> Sett;
        for(int num: arr) {
            Sett.insert(num);
        }
        int count = 0;
        for(int num:arr) {
            if(Sett.find(num+1) != Sett.end())
            count++;
        }
        return count;
    }
};