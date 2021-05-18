#uses two dictionaries one for the counting the frequency and another for storing indices
# not an optimized solution though

class Solution:
    def firstUniqChar(self, s: str) -> int:
        Dict_for_count,Dict_for_index = {s[i]:0 for i in range(len(s))},{s[i]:i for i in range(len(s))}

        dict_keys=[keys for keys in Dict_for_count.keys()]
        
        for i in range(len(s)):
             Dict_for_count[s[i]]+=1
                
        for i in Dict_for_count:
            if Dict_for_count[i]==1: #returns the first time a unique character is encountered
                return Dict_for_index[i]
                
        return -1
      
 #tip : you can use next(iter(d.values()))  # returns first value of dict d
