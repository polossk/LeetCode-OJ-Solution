class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        def loc(ch): return ord(ch) - ord('a')
        
        fqcs = [0 for _ in range(26)]
        for ch in chars: fqcs[loc(ch)] += 1
        ret = 0
        for word in words:
            tmp = fqcs[:]
            flag = 1
            for ch in word:
                if tmp[loc(ch)] == 0:
                    flag = 0
                    break
                else:
                    tmp[loc(ch)] -= 1
            ret += len(word) if flag == 1 else 0
        return ret