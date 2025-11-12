class Solution {
public:
   int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        int best = 0;
        int i = 1; // i will try to be the peak

        while (i < n - 1) {
            // check if i is a peak
            bool isPeak = (arr[i-1] < arr[i]) && (arr[i] > arr[i+1]);
            if (!isPeak) {
                i++;
                continue;
            }

            // expand left (strictly increasing towards i)
            int l = i;
            while (l > 0 && arr[l-1] < arr[l]) l--;

            // expand right (strictly decreasing away from i)
            int r = i;
            while (r + 1 < n && arr[r] > arr[r+1]) r++;

            best = max(best, r - l + 1);

            // jump i to r to avoid re-processing inside this mountain
            i = r;
        }
        return best;
    }
};