class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> queue ;
        int n = arr.size();
        vector<bool> seen (n , false);
        queue.push(start);
        seen[start] = true;
        while(!queue.empty()) {
            int current = queue.front();
            queue.pop();
            if(arr[current] == 0) {
                return true;
            }
            for(int change : {-arr[current], arr[current]}) {
                int nextpos = current + change;
                if(nextpos >= 0 && nextpos < arr.size() && !seen[nextpos]) {
                    queue.push(nextpos);
                    seen[nextpos] = true;
                }
            }
        }
        return false;
    }
};