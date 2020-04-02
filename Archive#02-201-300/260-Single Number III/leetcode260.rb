# @param {Integer[]} nums
# @return {Integer[]}
def single_number(nums)
  hoge = nums.reduce(:^)
  hoge &= -hoge
  a = nums.select { |e| e & hoge == 0 }.reduce(:^)
  b = nums.select { |e| e & hoge != 0 }.reduce(:^)
  [a, b]
end