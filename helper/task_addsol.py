import os
import sys
import glob
import re
from operator import itemgetter
# from functools import cmp_to_key

PATH_REPLACE_CHARS = [
    ("\\", "/"),
    ("#", "%23"),
    (" ", "%20"),
    ("(", "%28"),
    (")", "%29")
]


def problem():
    return {
        "cata": 0, # 0 for leetcode, 1 for cci, 2 for cof
        "id": 0,
        "title": "",
        "show_id": "",
        "href_id": "",
        "difficulty": "",
        "tags": [],
        "path": "",
        "cpp?": False,
        "python?": False,
        "ruby?": False,
        "java?": False,
    }


def locate_leetcode(data):
    p_id = data["id"]
    a_id = p_id // 100 # archive id
    data["show_id"] = f"{p_id:03d}"
    data["href_id"] = f"{p_id:03d}"
    target = glob.glob(f"Archive#{a_id:02d}*/{p_id:03d}-*/README.md")
    if len(target) > 1:
        print(target)
        return data
    return data, target[0]


def locate_cci(data):
    p_id = data["id"]
    data["show_id"] = f"面试题 {p_id // 100:02d}.{p_id % 100:02d}"
    data["href_id"] = f"cci{p_id:04d}"
    target = glob.glob(f"Archive#CCI/{p_id:04d}-*/README.md")
    if len(target) > 1:
        print(target)
        return data
    return data, target[0]


def locate_cof(data):
    p_id = data["id"]
    if p_id % 10 == 0:
        # without sub problem
        p_id //= 10
        data["show_id"] = f"面试题 {p_id:02d}"
        data["href_id"] = f"cof{p_id:02d}"
        target = glob.glob(f"Archive#COF/{p_id:02d}-*/README.md")
        if len(target) > 1:
            print(target)
            return data
    else:
        # with sub problem
        p_id, sub_id = p_id // 10, p_id % 10
        show_id_sub = ["", "I", "II", "III"]
        href_id_sub = ["", "a", "b", "c"]
        data["show_id"] = f"面试题 {p_id:02d}-{show_id_sub[sub_id]}"
        data["href_id"] = f"cof{p_id:02d}{href_id_sub[sub_id]}"
        target = glob.glob(f"Archive#COF/{p_id:02d}{href_id_sub[sub_id]}-*/README.md")
        if len(target) > 1:
            print(target)
            return data
    return data, target[0]


def finish(path, data):
    # path
    href = "\\" + path[:-10]
    for (s, t) in PATH_REPLACE_CHARS:
        href = href.replace(s, t)
    data["path"] = href
    # title, difficulty, tags
    with open(path, 'r', encoding="utf-8") as fin:
        title_line = fin.readline()
        fin.readline()
        dtags = fin.readline()
        data["title"] = (title_line.strip())[2:]
        results = re.findall(r"!\[([-\w]+)\]", dtags)
        data["difficulty"] = results[0]
        data["tags"] = results[1:]
    # codes
    meta = path[:-9]
    for src, attr in zip(["*.cpp", "*.py", "*.rb", "*.java"],
                         ["cpp?", "python?", "ruby?", "java?"]):
        if len(glob.glob(meta + src)) > 0:
            data[attr] = True
    return data


LOCATE = [locate_leetcode, locate_cci, locate_cof]


def analyze_target(input):
    data = problem()
    cata, p_id = 0, 0
    if input[0].upper() == "L":
        cata, p_id = 0, int(input[8:]) # leetcode
    elif input[1].upper() == "C":
        cata, p_id = 1, int(input[3:]) # cci
    else:
        cata, helper = 2, input[3:] # cof
        offset = {"a": 1, "b": 2, "c": 3}
        if helper[-1] in {"a", "b", "c"}:
            p_id = int(helper[:-1]) * 10 + offset[helper[-1]]
        else:
            p_id = int(helper) * 10
    data["cata"] = cata
    data["id"] = p_id
    data, path = LOCATE[cata](data)
    data = finish(path, data)
    return data


def setup_index(cata, show_id, href_id, difficulty, title, codes):
    value = f"| {show_id} | {difficulty} | [{title}][{href_id}] |"
    for flag in codes:
        value += ":o: |" if flag else " |"
    def check(line):
        if line[0] == '\n' or line[0] == '#': return False
        line_id = line.split("|")[1].strip()
        return cmpkey_show_id(show_id) < cmpkey_show_id(line_id)
    return check, value + '\n'


def setup_path(cata, href_id, path):
    value = f"[{href_id}]: {path}"
    def check(line):
        if line[0] == '\n' or line[0] == '#': return False
        line_id = line.split(":")[0][1:-1]
        return cmpkey_href_id(href_id) < cmpkey_href_id(line_id)
    return check, value + '\n'


def setup_tags(tags_cache):
    tags_cache.sort(key=itemgetter(1, 0))
    tags = []
    for href_id, tag in tags_cache:
        if len(tags) == 0:
            tags.append((tag, [href_id]))
        elif tag == tags[-1][0]:
            tags[-1][1].append(href_id)
        else:
            tags.append((tag, [href_id]))
    return tags


def cmpkey_href_id(a):
    clean_a = a.strip('[').strip(']').split('][')[0]
    value_a = 0
    if clean_a[0] == "c":
        value_a += 10000 if clean_a[1] == "c" else 20000
        if value_a == 20000:
            offset = {"a": 1, "b": 2, "c": 3}
            if clean_a[-1] in {"a", "b", "c"}:
                clean_a = int(clean_a[3:-1]) * 10 + offset[clean_a[-1]]
            else:
                clean_a = int(clean_a[3:]) * 10
        else:
            clean_a = int(clean_a[3:])
    return value_a + int(clean_a)


def cmpkey_show_id(a):
    clean_a = a.strip('[').strip(']').split('][')[0]
    value_a = 0
    if clean_a[0] == "面":
        value_a += 10000 if clean_a.find('.') != -1 else 20000
        clean_a = clean_a.replace("面试题 ", "").replace(".", "")
        if value_a == 20000:
            offset = {"I": 1, "II": 2, "III": 3}
            ret = clean_a.split('-')
            if len(ret) > 1:
                clean_a = int(ret[0]) * 10 + offset[ret[1]]
            else:
                clean_a = int(ret[0]) * 10
        else:
            clean_a = int(clean_a)
    return value_a + int(clean_a)


def pass_line_in_index(line):
    if line[0] == "*": return True # it is old item
    if line[:5] == "| ID ": return True # it is the table header
    if line[:5] == "|    ": return True # it is the table header
    if line[:5] == "| ---": return True # it is the table line
    return False

def main():
    worklist = [analyze_target(_) for _ in sys.argv[1:]]
    worklist.sort(key=itemgetter("cata", "id"))
    index_additions, tags_cache, href_additions = [], [], []
    get_codes = itemgetter("cpp?", "python?", "ruby?", "java?")
    get_index = itemgetter("cata", "show_id", "href_id", "difficulty", "title")
    get_paths = itemgetter("cata", "href_id", "path")
    for elem in worklist:
        index_additions.append(setup_index(*get_index(elem), get_codes(elem)))
        for tag in elem["tags"]:
            tags_cache.append((elem["href_id"], tag))
        href_additions.append(setup_path(*get_paths(elem)))
        print(elem)
    
    
    tags_modification = setup_tags(tags_cache)

    for host in [index_additions, tags_cache, href_additions, tags_modification]:
        for elem in host:
            print(elem)
        print()
    
    
    host = open("README.md", 'r', encoding="utf-8").readlines()
    finished = []
    # find index block
    while len(host) > 0:
        line, host = host[0], host[1:]
        finished.append(line)
        if line[:5] == "### A": # find the first line of ### Archive#00:
            break
    # deal index
    sp_judge_0 = lambda line: line[:5] == "### L"
    sp_judge_1 = lambda line: line[-2] == "F"
    sp_judge_2 = lambda line: line[:5] == "### T"
    sp_judge_idx, sp_judges = 0, [sp_judge_0, sp_judge_1, sp_judge_2]

    while len(host) > 0 and len(index_additions) > 0:
        line, host = host[0], host[1:]
        finished.append(line)
        if len(line) < 3: continue # empty line
        if line[0] == "#": # it is title or subtitle
            if sp_judges[sp_judge_idx](line):
                tmp = (1 + sp_judge_idx) * 10000
                while (len(index_additions) > 0):
                    check, value = index_additions[0]
                    value_cmp = cmpkey_show_id(value.split("|")[1].strip())
                    if value_cmp < tmp:
                        finished.append(value)
                        finished[-2], finished[-1] = finished[-3], finished[-2]
                        finished[-3] = value
                        index_additions = index_additions[1:]
                        # for e in finished[-4:]: print(4, e, end="")
                        # print(index_additions)
                        # input()
                    else: break
                sp_judge_idx += 1
            continue
        if pass_line_in_index(line): continue
        check, value = index_additions[0]
        # print(1, line, end="")
        if check(line):
            flag = False
            if len(host[0]) < 3:
                flag = True
            if check(host[0]) == True:
                flag = True
            if flag:
                finished[-1] = value
                host = [line] + host
                index_additions = index_additions[1:]
                # for e in finished[-4:]: print(3, e, end="")
                # print(index_additions)
                # input()
        # print(2, check(line), check(host[0]))
    # find tag block
    while len(host) > 0:
        line, host = host[0], host[1:]
        finished.append(line)
        if line[:5] == "#### ": # find the first line of #### Programming Fundamental
            break
    # deal tag block
    for tag, sols in tags_modification:
        head = f"* ![{tag}]"
        for idx, line in enumerate(host):
            if line[0] != '*': continue
            if head != line[:len(head)]: continue
            things = line.split()
            header, rest = " ".join(things[:2]), [_.strip(',') for _ in things[2:]]
            rest.extend([f"[{sol}][{sol}]" for sol in sols])
            rest = list(set(rest))
            rest.sort(key=cmpkey_href_id)
            host[idx] = header + " " + ", ".join(rest) + "\n"
            # print(6, host[idx:idx+2])
            # input()
            break
    # find href block
    while len(host) > 0:
        line, host = host[0], host[1:]
        finished.append(line)
        if line[:6] == "<!-- A": # find the first line of <!-- ARCHIVE #00 -->
            break
    # deal href
    sp_judge_0 = lambda line: line == "<!-- ARCHIVE #CCI -->\n"
    sp_judge_1 = lambda line: line == "<!-- ARCHIVE #COF -->\n"
    sp_judge_2 = lambda line: line == "<!-- hrefs end -->\n"
    sp_judge_idx, sp_judges = 0, [sp_judge_0, sp_judge_1, sp_judge_2]

    while len(host) > 0 and len(href_additions) > 0:
        line, host = host[0], host[1:]
        finished.append(line)
        if len(line) < 3: continue # empty line
        if line[:5] == "<!-- ": # it is the group header
            # print(9, line, sp_judges[sp_judge_idx](line))
            if sp_judges[sp_judge_idx](line):
                tmp = (1 + sp_judge_idx) * 10000
                while (len(href_additions) > 0):
                    check, value = href_additions[0]
                    value_cmp = cmpkey_href_id(value.split(":")[0][1:-1])
                    # print(10, value_cmp, value)
                    if value_cmp < tmp:
                        finished.append(value)
                        finished[-2], finished[-1] = finished[-3], finished[-2]
                        finished[-3] = value
                        href_additions = href_additions[1:]
                        # for e in finished[-4:]: print(8, e, end="")
                        # print(href_additions)
                        # input()
                    else: break
                sp_judge_idx += 1
            continue
        check, value = href_additions[0]
        # print(1, line, end="")
        if check(line):
            flag = False
            if len(host[0]) < 3:
                flag = True
            if check(host[0]) == True:
                flag = True
            if flag:
                finished[-1] = value
                host = [line] + host
                href_additions = href_additions[1:]
                # for e in finished[-6:]: print(7, e, end="")
                # print(href_additions)
                # input()
        # print(2, check(line), check(host[0]))
    finished.extend(host)

    # backup
    # os.system("copy README.md README.md.bak")

    with open("README-new.md.", 'w', encoding="utf-8") as fout:
        fout.writelines(finished)

    
if __name__ == "__main__":
    main()

    