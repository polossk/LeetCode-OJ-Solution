class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        return [((i & 1) ^ (e == '(')) for i, e in enumerate(seq)]