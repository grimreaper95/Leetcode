#Minimum Operations to Make Array Equal

class Solution:
    def minOperations(self, n: int) -> int:
        Min_op=0
        for i in range(1,n,2):
            Min_op+= (n-i)
        return Min_op
      
Solution().minOperations(3)

#Determine if String Halves Are Alike

class Solution:
    def halvesAreAlike(self, s: str) -> bool:
        vowels="AaEeIiOoUu"
        res_first = s[0:len(s)//2]
        res_second = s[len(s)//2:]
        counter=0
        count1 = [each_letter for each_letter in res_first if each_letter in vowels] 
        counter=0
        count2 = [each_letter for each_letter in res_second if each_letter in vowels]
        return len(count1)==len(count2)
      
Solution().halvesAreAlike("Helloo")

#Letter Combinations of a Phone Number

class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        Dict= {'2':'abc','3':'def','4':'ghi','5':'jkl','6':'mno','7':'pqrs','8':'tuv','9':'wxyz'}
        digit_length,a=len(digits),[]
        if digits == "": return []
        def using_recursion(pos:int,s:str):
            if(pos==digit_length): a.append(s)
            else:
                letters = Dict[digits[pos]]
                for letter in letters:
                    using_recursion(pos+1,s+letter)
        using_recursion(0," ")
        return a
      
Solution().letterCombinations("")

