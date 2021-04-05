#first logic : run time exceeded
class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        Dict ={}
        # Global inversion
        for i in range(len(A)):
            Dict[A[i]]=i  # 1,0,2 --- 1:0,0:1,2:2
        #B=[]
        B=A.copy()
        A.sort()
        Sum=0
        for i in range(len(A)-1):
            val = Dict[A[i]]
            Sum+=val
            if val!=(len(A)-1-i):
                for keys in Dict:
                    if (Dict[keys]>val):
                        Dict[keys]-=1
            Dict.pop(A[i])
#         print('Sum:',Sum)   
        # Local inversion
        Sum2=0
        for i in range(len(B)-1):
                if B[i]>B[i+1]:
                    Sum2+=1
#         print('Sum2:',Sum2) 
#         print('B:',B)
        return Sum==Sum2

#submitted solution: 
class Solution:
    def isIdealPermutation(self, A: List[int]) -> bool:
        for i in range(len(A)):
            if abs(i - A[i]) > 1: return False
        return True
