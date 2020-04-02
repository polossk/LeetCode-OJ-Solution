class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        def remake(s: str) -> str:
            ret = []
            for ch in s: ret = ret + [ch] if ch != '#' else ret[:-1]
            return ret
        return remake(S) == remake(T)