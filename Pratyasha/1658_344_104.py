# 1678. Goal Parser Interpretation

class Solution:
    def interpret(self, command: str) -> str:
        command=command.replace('()','o')
        command=command.replace('(al)','al')
        return command
      
Solution().interpret("(al)G(al)()()G")

# class Solution:
#     def interpret(self, command: str) -> str:
#         return command.replace('()','o').replace('(al)','al')


#344. Reverse String

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        k=""
        for letter in range(len(s)//2):
            k=s[letter]
            s[letter] =s[len(s)-1-letter]
            s[len(s)-1-letter]=k
            
        # or just use print(s[::-1])
        
 Solution().reverseString(["h","e","l","l","o"])

# 104. Maximum Depth of Binary Tree

# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
        
class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if root==None:return 0
        return max(self.maxDepth(root.left),self.maxDepth(root.right))+1
      
