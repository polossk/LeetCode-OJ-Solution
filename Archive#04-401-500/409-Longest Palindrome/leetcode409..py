class Solution:
    def longestPalindrome(self, s: str) -> int:
        ret, odd = len(s), 0
        alphabet = {chr(ord(ch) + _):0 for ch in ['A', 'a'] for _ in range(26)}
        for ch in s:
            alphabet[ch] += 1
        odd = sum([1 for v in alphabet.values() if v % 2 == 1])
        return ret if odd == 0 else ret - odd + 1