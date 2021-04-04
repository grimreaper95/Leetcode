from typing import List

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        counts = [0] * 101
        for num in nums:
            counts[num] += 1
            print("num=",num,"counts=",counts[num])
        print(counts)
        counts.insert(0, 0)
        print(counts)
        for i in range(1,len(counts)):
            print("before:", i,counts[i])
            counts[i] = counts[i-1] + counts[i]
            print("after",i,counts[i])
            
        return [counts[num] for num in nums]
       
Solution().smallerNumbersThanCurrent([8,1,2,2,3]) 
