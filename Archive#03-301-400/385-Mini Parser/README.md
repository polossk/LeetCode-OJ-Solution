# Mini Parser

![Medium](https://img.shields.io/badge/-Medium-f0ad4e.svg) ![String](https://img.shields.io/badge/字符串-String-007ec6.svg) ![Stack](https://img.shields.io/badge/堆栈-Stack-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode385-cpp-f34b7d.svg)   | 16 ms   | 14.7 Mb      |
| ![python](https://img.shields.io/badge/leetcode385-py-3572A5.svg) | 68 ms   | 16.2 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode385-rb-701516.svg)   | 76 ms   | 10.8 Mb      |

## DESCRIPTION

Given a nested list of integers represented as a string, implement a parser to deserialize it.

Each element is either an integer, or a list -- whose elements may also be integers or other lists.

## NOTE

You may assume that the string is well-formed:

* String is non-empty.
* String does not contain white spaces.
* String contains only digits `0-9`, `[`, `-`, ` `, `]`.

## EXAMPLE 1

```plain
Given s = "324",

You should return a NestedInteger object which contains a single integer 324.
```

## EXAMPLE 2

```plain
Given s = "[123,[456,[789]]]",

Return a NestedInteger object containing a nested list with 2 elements:

1. An integer containing value 123.
2. A nested list containing two elements:
    i.  An integer containing value 456.
    ii. A nested list with one element:
         a. An integer containing value 789.
```

## SOLUTION

* 堆栈模拟

## CODE

### C++

```cpp
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    NestedInteger nextInt_cxx11(istringstream &&in)
    {
        int num;
        if (in >> num) return NestedInteger(num);
        in.clear(); in.get();
        NestedInteger ret;
        while (in.peek() != ']')
        {
            ret.add(nextInt_cxx11(std::move(in)));
            if (in.peek() == ',') in.get();
        }
        in.get();
        return ret;
    }
    NestedInteger nextInt(istringstream &in)
    {
        int num;
        if (in >> num) return NestedInteger(num);
        in.clear(); in.get();
        NestedInteger ret;
        while (in.peek() != ']')
        {
            ret.add(nextInt(in));
            if (in.peek() == ',') in.get();
        }
        in.get();
        return ret;
    }
public:
    NestedInteger deserialize(string s)
    {
        // C++11 version, using Rvlue reference, T && var
        return nextInt_cxx11(std::move(istringstream(s)));
        // simple C++ version, without Rvalue reference
        // istringstream in(s);
        // return nextInt(in);
    }
};
```

### Python3

```python
# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        def nextInt() -> NestedInteger:
            num = ''
            while s[-1] in '0123456789-':
                num += s.pop()
            if num:
                return NestedInteger(int(num))
            s.pop()
            ret = NestedInteger()
            while s[-1] != ']':
                ret.add(nextInt())
                if s[-1] == ',':
                    s.pop()
            s.pop()
            return ret
        s = list(' ' + s[::-1])
        return nextInt()
```

### Ruby

```ruby
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
#
# class NestedInteger
#   def is_integer()
# 	  """
# 	  Return true if this NestedInteger holds a single integer, rather than a nested list.
# 	  @return {Boolean}
# 	  """
#
#   def get_integer()
# 	  """
# 	  Return the single integer that this NestedInteger holds, if it holds a single integer
# 	  Return nil if this NestedInteger holds a nested list
# 	  @return {Integer}
# 	  """
#
#   def set_integer(value)
# 	  """
# 	  Set this NestedInteger to hold a single integer equal to value.
# 	  @return {Void}
# 	  """
#
#   def add(elem)
# 	  """
# 	  Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
# 	  @return {Void}
# 	  """
#
#   def get_list()
# 	  """
# 	  Return the nested list that this NestedInteger holds, if it holds a nested list
# 	  Return nil if this NestedInteger holds a single integer
# 	  @return {NestedInteger[]}
# 	  """

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
```

### Java
