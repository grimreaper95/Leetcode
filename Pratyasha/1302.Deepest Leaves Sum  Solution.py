# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deepestLeavesSum(self, root: TreeNode) -> int:
        deepest,Sum=0,0
        def deepestLeaves(root: TreeNode,depth=0,):
            nonlocal deepest,Sum #to avoid the exception as python treats them as local to fn otherwise
            if root==None:return 0
            if root.left==None and root.right==None :
                if depth==deepest: Sum+=root.val
                elif depth>deepest:
                    deepest=depth
                    Sum=root.val
            else: 
                deepestLeaves(root.left,depth+1) 
                deepestLeaves(root.right,depth+1)
            return Sum
    
        return deepestLeaves(root)
    
    
    '''
   # cleaner solution
   
   def deepestLeavesSum(self, root: TreeNode) -> int:
	maxlevel = 0
	tsum = 0

	def dfs(node=root, level=0):
		nonlocal maxlevel, tsum
		if not node: return
		dfs(node.left, level+1)
		dfs(node.right, level+1)
		if maxlevel < level:
			maxlevel = level
			tsum = 0
		if maxlevel == level:
			tsum += node.val

	dfs()
	return tsum
'''
