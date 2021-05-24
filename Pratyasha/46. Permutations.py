'''
Check out the explanation for next permutation to understand the following code. I used the same algorithm but this time to find all the permutations. 
Note that the constraints of the problem were less so this worked but might not work for large values.  

Used a done variable to return value only once (not sure if that would really make any difference). 
'''


class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        length = len(nums) - 2
        final_list = []
        temp=[]
        temp[:] = nums[:]
        final_list.append(temp) # appends the first array in the final list
        done = 0
        
        if length < 0: done = 1
        
        #if length ==2 just swap and add to list
        elif length == 0:
            
            nums[0],nums[1]=nums[1],nums[0]
            final_list.append(nums)
            done = 1
        
        else:
            # print(temp)
            # using an extra while to find next permutation until nums is back again to the same value as old stored in temp
            while True:
                length = len(nums) - 2
                # print(temp)
                while length>=0:
                    if nums[length] < nums[length+1]:
                        pivot = nums[length]
                        break
                    length-=1

                if length <0: 
                    nums[:] = nums[::-1]
                    # print(nums)
                    final_list.append(nums[:])


                else : 
                    j = len(nums)-1
                    while True:
                        if nums[j] > pivot:
                            nums[length],nums[j] = nums[j], nums[length]
                            break
                        j-=1
                        
                    nums[length+1:] = nums[len(nums)-1:length:-1]
                    final_list.append(nums[:])
                    
                #since the above statement will append the first value again to the list we need to pop the last added element from the final_list before breaking 
                #the next permutation loop
                
                if temp == nums:
                    final_list.pop()
                    break
            
            done = 1
            
        if done : return final_list
        
        
        
        
        
''' Below solution is by using backtracking that should ideally be used to solve this problem'''

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        
        def dfs(nums,backtrack,result):
            if not backtrack:
                return(result.append(nums))
                
            for i in range(len(backtrack)):
                dfs(nums+[backtrack[i]],backtrack[:i]+backtrack[i+1:],result)
        res=[]
        dfs([],nums,res)
        return res
    
    
