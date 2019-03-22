# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum( nums, target )
    table = {}
    nums.each_with_index { |e, i|
        return [table[e] + 1, i + 1] if table.has_key?(e)
        table[target - e] = i
    }
end