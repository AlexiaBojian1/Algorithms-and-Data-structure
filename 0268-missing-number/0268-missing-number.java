class Solution {
    public int missingNumber(int[] nums) {
        Set<Integer> numSet = new HashSet<Integer>();
        for(int num:nums) numSet.add(num);

        int expected = nums.length+1;
        for (int number = 0; number < expected; number++) {
            if (!numSet.contains(number)) {
                return number;
            }
        }
        return -1;
    }
}