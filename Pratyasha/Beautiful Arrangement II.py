class Solution:
    def constructArray(self, n: int, k: int) -> List[int]:
        arr=[1]*n
        temp=k+1
        for i in range(1,k+1):
            if i%2==0: 
                arr[i]=arr[i-2]+1
            else:
                arr[i]=temp
                temp-=1
        temp=k+2       
        for i in range(k+1,n):
            arr[i]=temp
            temp+=1
        return arr
