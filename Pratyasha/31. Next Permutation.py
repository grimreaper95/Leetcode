'''
Need to divide the array in suffix and prefix and the point where division happens is denoted as a pivot. From n-1 we need to find the first element which is
responsible for the ascending order in the array eg. in 1,2,3 --> 2 because 3>2 and n=2>n=1. We call 2 a pivot. then we replace the pivot with the smallest value 
x in the suffix ( from pivot +1 to n-1) such that x>pivot starting from the right or n-1 towards pivot + 1. This ensures that a larger permutation is placed at pivot 
location and in the last step we arrange the suffix in ascending order to ensure that it's just the next permutation i.e., 1,3,2 . 

'''


class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        i = len(nums)-2
        if i==0:          #if n=2 we can just switch those numbers
            nums[0],nums[1]=nums[1],nums[0]

        else:
            while i>=0:
                if nums[i]<nums[i+1]:         #to find pivot
                    pivot = nums[i]
                    break
                i-=1

            # if pivot is not found , it implies that the series is in strictly decreasing order (3,2,1), 
            #in which case we have to return it in ascending order (1,2,3)
            if i<0:
                nums[:] = nums[::-1]      # note : if we do nums = nums[::-1] it would change the reference of the array so to make sure we are replacing values 
                                          # based on indices we use nums[:]

                
            else:
                j=len(nums)-1
                #to swap pivot with a suffix value
                while True:
                    if nums[j] > pivot :
                        nums[i],nums[j] = nums[j],nums[i]
                        break
                    j-=1
                
                #to ensure that the order post swapping makes it the next permutation
                #note : since till pivot it was a weakly decreasing series we just have to swap the order , hence -1 
                
                nums[i+1:]=nums[len(nums)-1:i:-1]
