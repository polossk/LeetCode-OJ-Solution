# @param {Integer[]} nums1
# @param {Integer[]} nums2
# @return {Float}
def find_median_sorted_arrays(nums1, nums2)
  a, b = [nums1, nums2].sort_by(&:size)
  m, n = a.size, b.size
  hoge = (m + n - 1) / 2
  i = (0...m).bsearch { |i| hoge - i - 1 < 0 || a[i] >= b[hoge - i - 1] } || m
  tmp = (a[i, 2] + b[hoge - i, 2]).sort
  (tmp[0] + tmp[1 - (m + n) % 2]) / 2.0
end