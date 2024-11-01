class Solution {
public:
    int trap(vector<int>& height) {
        int right = height.size()-1;
        int left  =0;
        int result = 0;
        int maxright = height[right];
        int maxleft = height[left];
        while(left<right) {
            if(maxleft<= maxright) {
                left++;
                maxleft = max(maxleft,height[left]);
                result += maxleft-height[left];
            } else{
                right--;
                maxright = max(maxright,height[right]);
                result += maxright-height[right];
            }
        }
        return result;
    }
};