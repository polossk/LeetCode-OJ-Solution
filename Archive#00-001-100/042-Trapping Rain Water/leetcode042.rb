# @param {Integer[]} height
# @return {Integer}
def trap(height)
  ans, cur, stk = 0, 0, []
  while cur < height.length do
    while stk.length > 0 && height[cur] > height[stk[-1]] do
      top = stk.delete_at(-1)
      if stk.length == 0 then
        break
      end
      width = cur - stk[-1] - 1
      depth = [height[cur], height[stk[-1]]].min - height[top]
      ans += width * depth
    end
    stk << cur
    cur += 1
  end
  ans
end