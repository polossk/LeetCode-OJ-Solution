# @param {String} s
# @return {String}
# 308 ms
def longest_palindrome(s)
    # manacher algorithm O(n)
    s = '$' + s;
    ma = s.each_char.map { |e| e + '#' }.inject(:+)
    l = ma.length
    mp = Array.new(l) { 0 }
    mx, id = 0, 0
    l.times { |i|
        mp[i] = mx > i ? [mp[2 * id - i], mx - i].min : 1
        while i - mp[i] > 0 && ma[i + mp[i]] == ma[i - mp[i]] do 
            mp[i] = mp[i] + 1
        end
        mx, id = i + mp[i], i if i + mp[i] > mx
    }
    # get palindrome
    pkg = mp.zip(0..l).max { |a, b| a[0] <=> b[0] }
    pos, val = pkg[1], pkg[0] - 1
    ma[pos - val .. pos + val].delete '#'.delete '$'
end