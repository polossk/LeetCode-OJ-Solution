# @param {String[]} strs
# @return {String[][]}
def group_anagrams(strs)
  tmp = Hash.new([])
  strs.each { |s| tmp[s.chars.sort.join("")] += [s] }
  tmp.values
end