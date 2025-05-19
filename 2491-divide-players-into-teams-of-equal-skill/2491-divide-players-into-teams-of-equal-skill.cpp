class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(), skill.end());
        int sum = skill[0] + skill[skill.size() - 1];
        int left = 0;
        int right = skill.size() - 1;
        long long result = 0;
        while(left < right) {
            if(skill[left] + skill[right] == sum) {
                result += skill[left] * skill[right];
                left++;
                right--;
            } else {
                return -1;
            }
        }
        return result;
    }
};