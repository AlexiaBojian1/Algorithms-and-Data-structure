class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n = len(nums)
        prefix_sum = [0] * n
        prefix_sum[0] = nums[0]
        for i in range(1,n):
            prefix_sum[i] = prefix_sum[i - 1] + nums[i]

        count = sum(
            1 for i in range(n - 1) if prefix_sum[i] >= prefix_sum[-1] - prefix_sum[i]
        )   

        return count 

        