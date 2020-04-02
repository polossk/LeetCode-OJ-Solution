# Definition for a binary tree node.
# class TreeNode
#     attr_accessor :val, :left, :right
#     def initialize(val)
#         @val = val
#         @left, @right = nil, nil
#     end
# end

# @param {TreeNode} root
# @return {Integer}
def dfs(node)
  return 0 unless node
  1 + [dfs(node.left), dfs(node.right)].max
end

# @param {TreeNode} root
# @return {Integer}
def max_depth(root)
  # dfs = lambda { |node| 
  #   return 0 unless node
  #   1 + [dfs.call(node.left), dfs.call(node.right)].max
  # }
  # dfs.call(root)
  dfs(root)
end