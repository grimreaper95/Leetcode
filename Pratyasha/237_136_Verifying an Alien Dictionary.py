#237. Delete Node in a Linked List

class Solution:
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val=node.next.val
        node.next=node.next.next
       
#136. Single Number

class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        single_result=0
        for i in nums:
            single_result^=i
        return single_result
      
#Verifying an Alien Dictionary

class Solution:
    def isAlienSorted(self, words: List[str], order: str) -> bool:
        Dict = {order[i]:i for i in range(len(order))}
        for i in range(len(words)-1):
            a,b=words[i],words[i+1]
            for j in range(len(a)):
                if j==len(b):return False # implies size of b is smaller which is lexicographically incorrect
                a_char,b_char=Dict[a[j]],Dict[b[j]]
                if(a_char>b_char):return False
                if(a_char<b_char):break
        return True      

Solution().isAlienSorted(["hello","leetcode"],"hlabcdefgijkmnopqrstuvwxyz")
