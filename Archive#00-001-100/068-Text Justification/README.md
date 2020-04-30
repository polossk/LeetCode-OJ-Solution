# Text Justification

![Hard](../../materials/-Hard-e05d44.svg) ![String](../../materials/字符串-String-007ec6.svg)

## RESULT

| Submission                                                        | Runtime | Memory Usage |
| ----------------------------------------------------------------- | ------- | ------------ |
| ![cpp](https://img.shields.io/badge/leetcode031-cpp-f34b7d.svg)   | 4 ms    | 6.8 Mb       |
| ![python](https://img.shields.io/badge/leetcode031-py-3572A5.svg) | 20 ms   | 13.9 Mb      |
| ![ruby](https://img.shields.io/badge/leetcode031-rb-701516.svg)   | -       | -            |

## DESCRIPTION

Given an array of words and a width *maxWidth*, format the text such that each line has exactly *maxWidth* characters and is fully (left and right) justified.

You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces `' '` when necessary so that each line has exactly maxWidth characters.

Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

For the last line of text, it should be left justified and no **extra** space is inserted between words.

## NOTE

* A word is defined as a character sequence consisting of non-space characters only.
* Each word's length is guaranteed to be greater than 0 and not exceed *maxWidth*.
* The input array `words` contains at least one word.

Of course, the context of these characters also matters in the input.

## EXAMPLE 1

```plain
Input:
words = ["This", "is", "an", "example", "of", "text", "justification."]
maxWidth = 16
Output:
[
   "This    is    an",
   "example  of text",
   "justification.  "
]
```

## EXAMPLE 2

```plain
Input:
words = ["What","must","be","acknowledgment","shall","be"]
maxWidth = 16
Output:
[
  "What   must   be",
  "acknowledgment  ",
  "shall be        "
]
Explanation: Note that the last line is "shall be    " instead of "shall     be",
             because the last line must be left-justified instead of fully-justified.
             Note that the second line is also left-justified becase it contains only one word.
```

## EXAMPLE 3

```plain
Input:
words = ["Science","is","what","we","understand","well","enough","to","explain",
         "to","a","computer.","Art","is","everything","else","we","do"]
maxWidth = 20
Output:
[
  "Science  is  what we",
  "understand      well",
  "enough to explain to",
  "a  computer.  Art is",
  "everything  else  we",
  "do                  "
]
```

## SOLUTION

* 贪心确定一行放哪些单词，并存在 `line` 当中
* 为 `line` 的单词（除了最后一个）分配多余空格
* 为最后一行在尾部添加空格

## CODE

### C++

```cpp
class Solution
{
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        vector<string> ret, line;
        int num = 0;
        for (int i = 0, sz = words.size(); i < sz; i++)
        {
            string word = words[i];
            if (num + word.size() + line.size() > maxWidth)
            {
                int length = line.size() - 1 + int(line.size() == 1);
                for (int j = 0; j < maxWidth - num; j++)
                {
                    line[j % length] += ' ';
                }
                ret.push_back(std::accumulate(line.begin(), line.end(), string("")));
                line.clear(); num = 0;
            }
            line.push_back(word);
            num += word.size();
        }
        string _ = std::accumulate(std::next(line.begin()), line.end(), *line.begin(),
            [](string a, string b) -> string { return a + " " + b; });
        for (int i = 0, sz = _.size(); i + sz <maxWidth; i++, _ += ' ');
        ret.push_back(_);
        return ret;
    }
};
```

### Python3

```python
class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        ret, line, num = [], [], 0
        for word in words:
            if num + len(line) + len(word) > maxWidth:
                for i in range(maxWidth - num):
                    line[i % (len(line) - 1 or 1)] += ' '
                ret.append(''.join(line))
                line, num = [], 0
            line += [word]
            num += len(word)
        return ret + [' '.join(line).ljust(maxWidth)]
```

### Ruby

### Java
