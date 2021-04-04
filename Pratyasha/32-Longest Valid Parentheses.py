class Solution:
    def longestValidParentheses(self, s: str) -> int:
        stack=[]
        stack.append(-1)
#         print(stack)
        counter=0
        for i in range(len(s)):
            if s[i]=='(':
                stack.append(i)
#                 print(stack)
            elif s[i]==')' and stack:
                stack.pop()
#                 print(stack)
                if stack:
                    counter=max(counter,i-stack[len(stack)-1])
#                     print('counter=',counter)
                else :
                    stack.append(i)
        return counter
