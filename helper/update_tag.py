import glob

TAGS = {
    r'数组-Array-': r'数组-Array-',
    r'字符串-String-': r'字符串-String-',
    r'位运算-Bit_Manipulation-': r'位运算-Bit_Manipulation-',
    r'回溯法-Backtracking-': r'回溯法-Backtracking-',
    r'二分查找-Binary_Search-': r'二分查找-Binary_Search-',
    r'广度优先搜索-Breadth--first_Search-': r'广度优先搜索-Breadth--first_Search-',
    r'深度优先搜索-Depth--first_Search-': r'深度优先搜索-Depth--first_Search-',
    r'分治法-Divide_and_Conquer-': r'分治法-Divide_and_Conquer-',
    r'动态规划-Dynamic_Programming-': r'动态规划-Dynamic_Programming-',
    r'双指针法-Two_Pointers-': r'双指针法-Two_Pointers-',
    r'滑窗法-Sliding_Window-': r'滑窗法-Sliding_Window-',
    r'图-Graph-': r'图-Graph-',
    r'哈希表-Hash_Table-': r'哈希表-Hash_Table-',
    r'堆-Heap-': r'堆-Heap-',
    r'链表-Linked_List-': r'链表-Linked_List-',
    r'队列-Queue-': r'队列-Queue-',
    r'堆栈-Stack-': r'堆栈-Stack-',
    r'树-Tree-': r'树-Tree-',
    r'并查集-Union_Find-': r'并查集-Union_Find-',
    r'数学-Math-': r'数学-Math-',
    r'设计-Design-': r'设计-Design-',
    r'构造法-Structured_Approach-': r'构造法-Structured_Approach-',
} # oldname newname


def main():
    # reduce
    tags = dict(TAGS)
    for k, v in TAGS.items():
        if k == v:
            tags.pop(k)
    tot = 0
    worklist = glob.glob("*/*/*.md")
    for filename in worklist:
        text = []
        with open(filename, 'r', encoding='utf-8') as fin:
            text = fin.readlines()
        hit = 0
        for k, v in tags.items():
            if text[2].find(k) < 0:
                continue
            text[2] = text[2].replace(k, v)
            hit += 1
        if hit == 0:
            continue
        tot += 1
        with open(filename, 'w', encoding='utf-8') as fout:
            fout.writelines(text)
        print(f'{filename} done, replace {hit} point(s)')
    print(f'Update {tot} file(s). Job done.')


if __name__ == "__main__":
    main()
