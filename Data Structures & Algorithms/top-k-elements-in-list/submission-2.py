class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        nums_dict = dict(Counter(nums))
        nums_list = sorted(nums_dict, key=nums_dict.get, reverse=True)
        return nums_list[:k]