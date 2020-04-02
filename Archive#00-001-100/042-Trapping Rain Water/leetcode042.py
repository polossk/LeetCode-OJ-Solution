class Solution:
    def trap(self, height: List[int]) -> int:
        ans, cur, stk = 0, 0, []
        while cur < len(height):
            while len(stk) != 0 and height[cur] > height[stk[-1]]:
                top, stk = stk[-1], stk[:-1]
                if len(stk) == 0: break
                width = cur - stk[-1] - 1
                depth = min(height[cur], height[stk[-1]]) - height[top]
                ans += width * depth
            stk.append(cur)
            cur += 1
        return ans