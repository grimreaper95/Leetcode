class Solution:
    def moveZeroes(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        i,j=0,0
        
        while i+j<n:
            if nums[i]==0:
                nums.append(nums.pop(i))
                j+=1
            else : i+=1
