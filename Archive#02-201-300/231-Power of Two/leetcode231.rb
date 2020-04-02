# @param {Integer} n
# @return {Boolean}
def is_power_of_two( n )
  return false if (n % 2 != 0 && n != 1)
  return false if (n < 2 && n != 1)
  return true if (1..2).include?(n)
  is_power_of_two(n / 2)
end