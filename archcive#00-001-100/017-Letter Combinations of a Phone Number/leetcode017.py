from typing import List


class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        return [] if len(digits) == 0 else self.__dfs(digits)

    def __dfs(self, digits: str) -> List[str]:
        return self.__mapping[digits] if len(digits) == 1 else [
            _1 + _2 for _1 in self.__mapping[digits[0]]
            for _2 in self.__dfs(digits[1:])
        ]

    __mapping = {
        '2': ["a", "b", "c"],
        '3': ["d", "e", "f"],
        '4': ["g", "h", "i"],
        '5': ["j", "k", "l"],
        '6': ["m", "n", "o"],
        '7': ["p", "q", "r", "s"],
        '8': ["t", "u", "v"],
        '9': ["w", "x", "y", "z"],
    }
