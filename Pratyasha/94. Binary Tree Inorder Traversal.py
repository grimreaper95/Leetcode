# idea is to stack root.left until it becomes null and then pop the top which will be our list element and then set the right of that leftmost node 
# as the current node and follow the process until the stack becomes null


class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        current = root    # to traverse the tree
        stack = []
        final_list = []
        while True:
            if current is not None:  #keep appending to stack until leftmost value becomes null for the current node
                stack.append(current)
                current = current.left
            
            #if the stack is not empty it needs current values to be popped from top 
            elif stack:    
                current = stack.pop()
                final_list.append(current.val)
                
                # tried to implement the following that pops the root along with the root.left if the root.right is also null but since this requires stack to be 
                #non-empty the operation takes longer than just setting the current.right to current will will eventually check in the next iteration if it's null 
                #or not
                # if current.right is None and stack:
                #     current = stack.pop()
                #     final_list.append(current.val)
                
                current = current.right
            
            else:
                break
                
        return final_list
