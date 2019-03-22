# @param {String} s
# @return {Boolean}
def is_palindrome(s)
    tmp = s.scan(/[A-Za-z0-9]/).join.downcase
    tmp == tmp.reverse
end