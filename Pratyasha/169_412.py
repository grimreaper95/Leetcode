#169. Majority Element

class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        count=1
        major =nums[0]
        
        for i in nums[1:]:
            
            if i==major:
                count+=1
                
            else:
                count-=1
                if count==0:
                    major=i
                    count=1
         
        return major
      
#412. Fizz Buzz

class Solution:
    def fizzBuzz(self, n: int) -> List[str]:
        arr = [0]*n
        for i in range(n):
            if (i+1)%15==0:
                arr[i]="FizzBuzz"
            elif (i+1)%3==0:
                arr[i]="Fizz"
            elif (i+1)%5==0:
                arr[i]="Buzz"
            else:
                arr[i]=str(i+1)
        return arr
