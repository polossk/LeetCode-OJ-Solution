class Solution:
    def canThreePartsEqualSum(self, A: List[int]) -> bool:
        s = sum(A)
        if s % 3 != 0: return False
        s //= 3
        current, flag = 0, 0
        for i, e in enumerate(A):
            current += e
            if flag == 0:
                flag = 1 if current == s else 0
            elif flag == 1:
                if current == s * 2 and i + 1 < len(A):
                    return True
        return False