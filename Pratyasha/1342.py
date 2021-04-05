#My Solution:
class Solution:
    def numberOfSteps(self, num: int) -> int:
        counter=0
        while(num!=0):
            if(num%2==0):
                num/=2
                counter+=1
            else:
                num-=1
                counter+=1
        return counter
      
#Expected Bitwise Solution:
class Solution:
    def numberOfSteps (self, num: int) -> int:
        bitstring = bin(num)[2:] # [2:] will remove the '0b' that is prepended to each bitstring by bin()
        return len(bitstring) - 1 + bitstring.count('1')
