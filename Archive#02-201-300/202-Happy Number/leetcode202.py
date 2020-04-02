class Solution:
    ans = [False, True, False, False, False, False, False, True,
           False, False, True, False, False, True, False, False]
    def next(self, n: int) -> int:
        return sum([int(_) ** 2 for _ in str(n)])
    
    def isHappy(self, n: int) -> bool:
        while n >= 16: n = self.next(n)
        return self.ans[n]