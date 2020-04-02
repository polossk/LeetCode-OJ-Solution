# @param {Integer[]} nums
# @return {Integer}
def single_number(nums)
  a, b = 0, 0
  nums.each{ |e| a, b = (a ^ e) & (~b), (b ^ e) & (a ^ b) }
  a
end