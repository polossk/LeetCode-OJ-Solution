class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        t = [ch for ch in s.lower() if ch.isalnum()]
        return t == t[::-1]