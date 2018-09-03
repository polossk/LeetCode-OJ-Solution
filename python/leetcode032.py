class Solution:
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = len(s)
        if l < 2: return 0
        maxlen = 0
        dp = [0 for _ in range(l)]
        for i in range(1, l):
            if s[i] == ')':
                j = i - 1 - dp[i - 1]
                if j >= 0 and s[j] == '(':
                    dp[i] = dp[i - 1] + 2
                    if j - 1 >= 0:
                        dp[i] += dp[j - 1]
        return max(dp)