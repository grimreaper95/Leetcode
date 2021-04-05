#My Solution:

class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        Shuffle_Dict={}
        for i in range(len(indices)):
            Shuffle_Dict[indices[i]]=s[i]
        x= list(Shuffle_Dict.keys())
        x.sort()
        shuffled_str=[]
        print(x)
        for i in x:
            shuffled_str.append(Shuffle_Dict[i])
        return ''.join(shuffled_str)
      
#Better solution using enumerate:

class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        res = [''] * len(s)
        for index, char in enumerate(s):
            res[indices[index]] = char
        return "".join(res)
