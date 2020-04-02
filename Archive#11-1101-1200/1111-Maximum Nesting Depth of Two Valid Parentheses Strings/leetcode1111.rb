# @param {String} seq
# @return {Integer[]}
def max_depth_after_split(seq)
  seq.each_char.to_a.zip((0..seq.length)).map { |ch, i|
    (i & 1 == 1) ^ (ch == '(') ? 1 : 0
  }
end