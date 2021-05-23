class Solution:
    def titleToNumber(self, columnTitle: str) -> int:
        # Dict={letter:ord(letter)-64 for letter in "ABCDEFGHIJKLMNOPQRSTUVWXYZ"}
        length = len(columnTitle)
        Sum=0
        for i in range(length):
            Sum+=(ord(columnTitle[i])-64)*26**(length-1-i)   
        return Sum
      
      
      
#168. Excel Sheet Column Title
      
class Solution:
    def convertToTitle(self, columnNumber: int) -> str:
        Str=[]
        while columnNumber>0:
            Str.append(chr(65+((columnNumber-1)%26)))
            # print("remainder:",remainder)
            # print("columnNumber:",columnNumber)   
            columnNumber=(columnNumber-1)//26

        return(''.join(Str[::-1]))
            
      
      
