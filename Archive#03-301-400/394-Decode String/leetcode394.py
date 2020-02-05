class Solution:
    def decodeString(self, s: str) -> str:
        while '[' in s:
            s = re.sub(r'(\d+)\[([^\[^\]]*)\]', lambda m: int(m.group(1)) * m.group(2), s)
        return s