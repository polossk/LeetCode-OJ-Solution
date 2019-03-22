# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer[]}

def right_side_view(root)
    return [] if not root
    right = right_side_view(root.right)
    left = right_side_view(root.left)
    return [root.val] + right + left.drop(right.length)
end