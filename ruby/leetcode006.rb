# @param {String} s
# @param {Integer} num_rows
# @return {String}
def convert(s, num_rows)
    return s if num_rows == 1 or num_rows >= s.length
    l, index, step = [''] * num_rows, 0, 1
    s.each_char { |x|
        l[index] += x;
        step = 1 if index == 0
        step = -1 if index == num_rows - 1
        index += step
    }
    l.join()
end