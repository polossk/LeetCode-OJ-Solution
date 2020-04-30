# @param {String} s
# @param {Integer[][]} shift
# @return {String}
def string_shift(s, shift)
  sz = s.length()
  movement = shift.map {|e| e[0] == 1 ? e[1] : -e[1] }.inject(:+) % sz
  return s if movement == 0
  s[-movement..-1] + s[0...-movement]
end