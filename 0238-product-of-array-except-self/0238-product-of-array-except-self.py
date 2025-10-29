class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        prefix = 1
        postfix = 1
        res = [0] * n
        for i, num in enumerate(nums):
            res[i] = prefix
            prefix *= num

        for i in range(len(nums) - 1 , - 1, -1):
            res[i] = res[i] * postfix
            postfix *= nums[i]

        return res        

        