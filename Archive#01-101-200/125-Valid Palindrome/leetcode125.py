class Solution:
    def isPalindrome(self, s: str) -> bool:
        t = [ch for ch in s.lower() if ch.isalnum()]
        return t == t[::-1]