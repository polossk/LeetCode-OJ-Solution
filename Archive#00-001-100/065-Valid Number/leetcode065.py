import re

class Solution:
    hoge = re.compile("^[\ ]*[+-]?(\d+\.?\d*|\d*\.?\d+)(e[+-]?\d+)?[\ ]*$")
    
    def isNumber(self, s: str) -> bool:
        return bool(self.hoge.match(s))