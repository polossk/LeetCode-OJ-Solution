class Solution:
    def countElements(self, arr: List[int]) -> int:
        return sum(i + 1 in set(arr) for i in arr)