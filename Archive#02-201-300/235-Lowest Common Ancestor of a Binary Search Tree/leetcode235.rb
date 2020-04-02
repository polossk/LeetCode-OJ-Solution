# Definition for a binary tree node.
# class TreeNode
#   attr_accessor :val, :left, :right
#   def initialize(val)
#     @val = val
#     @left, @right = nil, nil
#   end
# end

# @param {TreeNode} root
# @param {TreeNode} p
# @param {TreeNode} q
# @return {TreeNode}
def lowest_common_ancestor(root, p, q)
  while (root != nil) do
    v, pv, qv = root.val, p.val, q.val
    if (v > [pv, qv].max) then
      root = root.left
    elsif (v < [pv, qv].min) then
      root = root.right
    else
      return root
    end
  end
end