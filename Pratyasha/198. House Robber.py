#consider that last two elements will always remain same because no two adjacent houses can be robbed. From the third last house, start taking the max in an 
#array starting from i+1 and update the current index i
#Do the same from third last index to first index 
#usually the first index will have the maximum value at the end but to avoid the cases with len(num = 2 or 3 we will just print the max of the new array

class Solution:
    def rob(self, nums: List[int]) -> int:
            temp_dp = nums[::-1]    #because traversing the inverted list from [2:] is easier so implement the above logic in reverse
            for i in range(2,len(nums)):
                temp_dp[i]+=max(temp_dp[:i-1])
            return max(temp_dp)
