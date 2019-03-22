# @param {String} s
# @return {Boolean}
def is_number(s)
    /\s*[+-]?(\d+\.\d+|\d+\.?|\.\d+)([eE][+-]?\d+)?\s*/.match(s).to_s == s and s.length > 0
end