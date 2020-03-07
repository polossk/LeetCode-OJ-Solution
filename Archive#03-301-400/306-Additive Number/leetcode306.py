# 1123581321 -> [1,1,2,3,5,18,13] => True
# 100101201302 -> [100,101,201,302] => True
# 112211221122 => False
class Solution:
    def isAdditiveNumber(self, num: str) -> bool:
        if len(num) < 3: return False
        return self.dfs(num, 0)
    
    def dfs(self, s, start):
        # select a, b from s, then check a + b = rest
        # print(">>> dfs(s, ", start, ")")
        for i in range(start, len(s) - 2):
            for j in range(i + 1, len(s)):
                a = int(s[start:i + 1])
                b = int(s[i + 1:j + 1])
                ans = str(a + b)
                s3 = s[j + 1:j + 1 + len(ans)]
                # print("i= ", i, "j= ", j, "a= ", a, "b= ", b, "ans= ", ans, "s3= ", s3, )
                if ans == s3:
                    if j + 1 + len(ans) == len(s): return True
                    rest = self.dfs(s, i + 1)
                    if rest: return True
                    break
                if b == 0: break
            if a == 0: return False
        return False


def main():
    runner = Solution().isAdditiveNumber
    tests = ['112358', '199100199', '111111', '010102']
    answers = [True, True, False, False]
    results = [runner(_) for _ in tests]
    for (_1, _2, _3) in zip(tests, results, answers):
        print("tests= ", _1, "result= ", _2, "answer= ", _3)


if __name__ == '__main__':
    main()
