# @param {String} s
# @param {String} t
# @return {Boolean}
def backspace_compare(s, t)
  def remake(s)
    ret = []
    s.each_char { |ch| ret = ch == '#' ? ret[0...-1] : ret + [ch] }
    ret
  end
  remake(s) == remake(t)
end