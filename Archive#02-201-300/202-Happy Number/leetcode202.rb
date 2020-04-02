# @param {Integer} n
# @return {Integer}
def get_next(n)
  n.to_s.each_char.map{|i| (i.to_i)**2 }.reduce(:+)
end


# @param {Integer} n
# @return {Boolean}
def is_happy(n)
  while n >= 8 do n = get_next(n) end
  n == 1 || n == 7
end