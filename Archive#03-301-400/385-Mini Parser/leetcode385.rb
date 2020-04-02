# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
#
# class NestedInteger
#   def is_integer()
#     """
#     Return true if this NestedInteger holds a single integer, rather than a nested list.
#     @return {Boolean}
#     """
#
#   def get_integer()
#     """
#     Return the single integer that this NestedInteger holds, if it holds a single integer
#     Return nil if this NestedInteger holds a nested list
#     @return {Integer}
#     """
#
#   def set_integer(value)
#     """
#     Set this NestedInteger to hold a single integer equal to value.
#     @return {Void}
#     """
#
#   def add(elem)
#     """
#     Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#     @return {Void}
#     """
#
#   def get_list()
#     """
#     Return the nested list that this NestedInteger holds, if it holds a nested list
#     Return nil if this NestedInteger holds a single integer
#     @return {NestedInteger[]}
#     """
#
# @param {String} s
# @return {NestedInteger}
def deserialize(s)
  define_method :dfs do
    num = ''
    while not s.empty? and "0123456789-".include? s[-1]
      num << s[-1]
      s.chop!
    end
    return NestedInteger.new(num.to_i) if not num.empty?
    s.chop!
    ret = NestedInteger.new()
    while s[-1] != ']'
      ret.add(dfs)
      s.chop! if s[-1] == ','
    end
    s.chop!
    return ret
  end
  s.reverse!
  return dfs
end