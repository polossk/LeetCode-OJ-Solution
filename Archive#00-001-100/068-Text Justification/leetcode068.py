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
