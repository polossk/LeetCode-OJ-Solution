# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def diameterOfBinaryTree(self, root: TreeNode) -> int:
        self.ret = 0
        def dfs(node: TreeNode):
            if not node: return 0
            l_depth = dfs(node.left)
            r_depth = dfs(node.right)
            self.ret = max(self.ret, l_depth + r_depth)
            return 1 + max(l_depth, r_depth)
        dfs(root)
        return self.ret