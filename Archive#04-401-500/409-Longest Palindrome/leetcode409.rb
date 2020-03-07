# @param {String} s
# @return {Integer}
def longest_palindrome(s)
  ret, odd = s.size, 0
  alphabet = {}
  ('A'..'Z').each{ |ch| alphabet[ch] = alphabet[ch.downcase] = 0 }
  s.each_char{ |ch| alphabet[ch] += 1}
  odd = alphabet.each_value.select { |value| value % 2 == 1 }.size
  odd == 0 ? ret : ret - odd + 1
end