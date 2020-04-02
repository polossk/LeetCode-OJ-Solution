import glob

FILE_PATTERN = {
    "cpp": "*.cpp",
    "python": "*.py",
    "ruby": "*.rb",
    "java": "*.java",
    "haskell": "*.hs",
}

IMG_GENERATOR = {
    "cpp": "![cpp](https://img.shields.io/badge/cpp-{0}-f34b7d.svg)",
    "python": "![python](https://img.shields.io/badge/python-{0}-3572A5.svg)",
    "ruby": "![ruby](https://img.shields.io/badge/ruby-{0}-701516.svg)",
    "java": "![java](https://img.shields.io/badge/java-{0}-b07219.svg)",
    "haskell": "![haskell](https://img.shields.io/badge/haskell-{0}-5e5086.svg)",
}

# CODEBASE_PATTERN = {
#     "LeetCode": r"Archive#\d\d",
#     "CCI": r"Archive#CCI",
#     "COF": r"Archive#COF",
#     "Unreleased": r"Archive#Unreleased",
#     # idx: 0 1 2 3 4 5 6 7 8 9
#     # s1:  A r c h i v e #\d\d -
#     # s2:  A r c h i v e # C C I
#     # s3:  A r c h i v e # C O F
#     # s4:  A r c h i v e # U n l e a s e d
# }

def main():
    catagory = {k:{ lang:0 for lang in FILE_PATTERN.keys() }
        for k in ["LeetCode", "CCI", "COF", "Unreleased"]}
    for k, v in FILE_PATTERN.items():
        files = glob.glob("*/*/" + v)
        for elem in files:
            if elem[9] == "C":
                catagory["CCI"][k] += 1
            elif elem[9] == "O":
                catagory["COF"][k] += 1
            elif elem[9] == "n":
                catagory["Unreleased"][k] += 1
            else:
                catagory["LeetCode"][k] += 1
    for k, v in catagory.items():
        cnts = sum(v.values())
        if cnts == 0:
            continue
        print(f"* {k}:")
        for lang, cnt in v.items():
            if cnt == 0:
                continue
            print(IMG_GENERATOR[lang].format(cnt))
        print("")

if __name__ == "__main__":
    main()
