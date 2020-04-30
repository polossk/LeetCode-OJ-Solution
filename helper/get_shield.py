import requests
import time

urls = {
"https://img.shields.io/badge/树-Tree-007ec6.svg": "树-Tree-007ec6.svg",
"https://img.shields.io/badge/位运算-Bit_Manipulation-007ec6.svg": "位运算-Bit_Manipulation-007ec6.svg",
"https://img.shields.io/badge/二分查找-Binary_Search-007ec6.svg": "二分查找-Binary_Search-007ec6.svg",
"https://img.shields.io/badge/广度优先搜索-Breadth--first_Search-007ec6.svg": "广度优先搜索-Breadth--first_Search-007ec6.svg",
"https://img.shields.io/badge/深度优先搜索-Depth--first_Search-007ec6.svg": "深度优先搜索-Depth--first_Search-007ec6.svg",
"https://img.shields.io/badge/分治法-Divide_and_Conquer-007ec6.svg": "分治法-Divide_and_Conquer-007ec6.svg",
"https://img.shields.io/badge/动态规划-Dynamic_Programming-007ec6.svg": "动态规划-Dynamic_Programming-007ec6.svg",
"https://img.shields.io/badge/贪心-Greedy-007ec6.svg": "贪心-Greedy-007ec6.svg",
"https://img.shields.io/badge/扫描线-Line_Sweep-007ec6.svg": "扫描线-Line_Sweep-007ec6.svg",
"https://img.shields.io/badge/双指针法-Two_Pointers-007ec6.svg": "双指针法-Two_Pointers-007ec6.svg",
"https://img.shields.io/badge/滑窗法-Sliding_Window-007ec6.svg": "滑窗法-Sliding_Window-007ec6.svg",
"https://img.shields.io/badge/排序-Sort-007ec6.svg": "排序-Sort-007ec6.svg",
"https://img.shields.io/badge/树状数组-Binary_Indexed_Tree-007ec6.svg": "树状数组-Binary_Indexed_Tree-007ec6.svg",
"https://img.shields.io/badge/图-Graph-007ec6.svg": "图-Graph-007ec6.svg",
"https://img.shields.io/badge/哈希表-Hash_Table-007ec6.svg": "哈希表-Hash_Table-007ec6.svg",
"https://img.shields.io/badge/堆-Heap-007ec6.svg": "堆-Heap-007ec6.svg",
"https://img.shields.io/badge/链表-Linked_List-007ec6.svg": "链表-Linked_List-007ec6.svg",
"https://img.shields.io/badge/保序映射-Ordered_Map-007ec6.svg": "保序映射-Ordered_Map-007ec6.svg",
"https://img.shields.io/badge/队列-Queue-007ec6.svg": "队列-Queue-007ec6.svg",
"https://img.shields.io/badge/线段树-Segment_Tree-007ec6.svg": "线段树-Segment_Tree-007ec6.svg",
"https://img.shields.io/badge/堆栈-Stack-007ec6.svg": "堆栈-Stack-007ec6.svg",
"https://img.shields.io/badge/Tire树-Tire-007ec6.svg": "Tire树-Tire-007ec6.svg",
"https://img.shields.io/badge/并查集-Union_Find-007ec6.svg": "并查集-Union_Find-007ec6.svg",
"https://img.shields.io/badge/几何-Geometry-007ec6.svg": "几何-Geometry-007ec6.svg",
"https://img.shields.io/badge/极小极大算法-Minimax-007ec6.svg": "极小极大算法-Minimax-007ec6.svg",
"https://img.shields.io/badge/设计-Design-007ec6.svg": "设计-Design-007ec6.svg",
"https://img.shields.io/badge/构造法-Structured_Approach-009688.svg": "构造法-Structured_Approach-009688.svg",
"https://img.shields.io/badge/模拟法-Simulation_Method-009688.svg": "模拟法-Simulation_Method-009688.svg",
"https://img.shields.io/badge/搜索法-Searching_Method-009688.svg": "搜索法-Searching_Method-009688.svg",
"https://img.shields.io/badge/位运算-Bit_Manipulation-009688.svg": "位运算-Bit_Manipulation-009688.svg",
"https://img.shields.io/badge/Tire树-Tire-009688.svg": "Tire树-Tire-009688.svg",
"https://img.shields.io/badge/约瑟夫环-Josephus-009688.svg": "约瑟夫环-Josephus-009688.svg",
"https://img.shields.io/badge/快速排序-QuickSort-009688.svg": "快速排序-QuickSort-009688.svg",
"https://img.shields.io/badge/归并排序-MergeSort-009688.svg": "归并排序-MergeSort-009688.svg",
"https://img.shields.io/badge/希尔排序-ShellSort-009688.svg": "希尔排序-ShellSort-009688.svg",
"https://img.shields.io/badge/堆排序-HeapSort-009688.svg": "堆排序-HeapSort-009688.svg",
}


for url, filepath in urls.items():
    file_data = requests.get(url, allow_redirects=True).content
    with open(filepath, 'wb') as handler:
        handler.write(file_data)
    print(filepath, "done.")
    time.sleep(1)
