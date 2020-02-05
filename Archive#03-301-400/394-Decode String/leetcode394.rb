# @param {String} s
# @return {String}
def decode_string(s)
  1 while s.gsub!(/(\d+)\[([^\[^\]]*)\]/) { $2 * $1.to_i }
  s
end