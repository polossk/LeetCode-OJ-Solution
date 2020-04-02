# @param {Integer[]} arr
# @return {Integer}
def count_elements(arr)
  cnt, brr = Hash.new, arr.sort
  cnt.default = 0
  ret = 0
  brr.each { |e| cnt[e] += 1 }
  cnt.each { |key, value| ret += cnt[key + 1] > 0 ? cnt[key] : 0 }
  ret
end