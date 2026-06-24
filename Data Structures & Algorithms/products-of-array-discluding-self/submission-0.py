class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        p = [0] * len(nums)
        s = [0] * len(nums)
        p[0] = nums[0]
        s[-1] = nums[-1]
        out = [0] * len(nums)
        for i in range(1,len(nums)):
            p[i] = p[i-1] * nums[i]
            s[-i-1] = s[-i] * nums[-i-1]
        out[0] = s[1]
        out[-1] = p[-2]
        for i in range(1,len(nums)-1):
            out[i] = p[i-1] * s[i+1]
        return out