'''
We have the constraints of not having in the same row, column and diagonal , this solution uses those contraints in line 20-21 and 
gives the column number as the output in queens that eventually is appended to result(line 16) which is modified in line 25 to give output in a desired format.
We use p-q and p+q where p is the row and q is the column for avoiding the same diagonal and column. Queens+[q] places the queen in that location if it doesn't
have any issue i.e., not present in xy_dif and xy_sum. 

'''


class Solution:
    
    def solveNQueens(self, n):
        def DFS(queens, xy_dif, xy_sum):
#             print("queens:",queens," xy_diff:",xy_dif," xy_sum:",xy_sum)
            p = len(queens)
#             print("p:",p)
            if p==n:
                result.append(queens)
#                 print("Result:",result)
                return None
            for q in range(n):
#                 print("q:",q)
                if q not in queens and p-q not in xy_dif and p+q not in xy_sum: 
                    DFS(queens+[q], xy_dif+[p-q], xy_sum+[p+q])  
        result = []
        DFS([],[],[])
        return [ ["."*i + "Q" + "."*(n-i-1) for i in sol] for sol in result]
