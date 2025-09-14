class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        long long zero1 = 0, zero2 = 0;

        for(int i1 : nums1) {
            if(i1 == 0) {
                zero1++;
                sum1++;
            }
            sum1 += i1;
        }

        for(int i2 : nums2) {
            if(i2 == 0) {
                zero2++;
                sum2++;
            }
            sum2 += i2;
        }

        if(!zero1 && sum2 > sum1 || !zero2 && sum1 > sum2) {
            return -1;
        } else {
            return max(sum1 , sum2 );
        }
    }
};