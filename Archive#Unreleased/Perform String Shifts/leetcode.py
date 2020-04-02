class Solution:
    def stringShift(self, s: str, shift: List[List[int]]) -> str:
        movement = sum((d * 2 - 1) * v for d, v in shift) % len(s)
        if movement == 0:
            return s
        else:
            return s[-movement:] + s[:-movement]
