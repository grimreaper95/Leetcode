#1281.Subtract the Product and Sum of Digits of an Integer
class Solution:
    def subtractProductAndSum(self, n: int) -> int:
        Sum=0
        Prod=1
        while n!=0:
            mod=n%10
#             print('mod:',mod)
            Sum+=mod
            Prod*=mod
            n=int(n/10)
#             print('n:',n)
        return Prod-Sum

#def subtractProductAndSum(self, n: int) -> int:
#    return eval('*'.join(str(n))) - eval('+'.join(str(n)))

Solution().subtractProductAndSum(114)

#1313. Decompress Run-Length Encoded List
class Solution:
    def decompressRLElist(self, nums: List[int]) -> List[int]:
        final_arr=[]
        for i in range(len(nums)):
            if(i%2!=0):
                 for j in range(nums[i-1]):
                         final_arr.append(nums[i])
        return final_arr

Solution().decompressRLElist([1, 2, 3, 4])
#[x for i in range(0, len(nums), 2) for x in [nums[i+1]] * nums[i] ]

#1720. Decode XORed Array

class Solution:
    def decode(self, encoded: List[int], first: int) -> List[int]:
        arr=[None] * (len(encoded)+1)
        arr[0]=first
        for i in range(1,len(encoded)+1):
            arr[i]=encoded[i-1]^arr[i-1]
        return arr  

Solution().decode([7,2,3,8,5,6],1)

''' def decode(self, A, first):
        return list(accumulate([first] + A, lambda x, y: x ^ y))
    def decode(self, A, first):
        res = [first]
        for a in A:
            res.append(res[-1] ^ a)
        return res '''
