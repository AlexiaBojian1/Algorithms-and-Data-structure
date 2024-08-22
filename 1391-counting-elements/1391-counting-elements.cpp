class Solution {
public:
    int countElements(vector<int>& arr) {
        set<int> sety;
        int count = 0;
         for(int num:arr) {
            sety.insert(num);
         }
         for(int num:arr){
            if(sety.find(num+1) != sety.end()) {
                count++;
            }
         }
         return count;
    }
};