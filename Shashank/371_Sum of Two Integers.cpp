class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;        
        int c0 = 0;
        for(int i = 0; i < 32;i++){
            int a0 = a & (1 << i);
            int b0 = b & (1 << i);
            if(a0 && b0){
                if(c0){
                    res = res | (1 << i);
                }
                else{
                    c0 = 1;
                }
            }
            else if(a0 || b0){
                if(c0){
                    //c0 = 0;
                }        
                else{
                    res = res | (1 << i);                    
                }
            }
            else{
                if(c0){
                    res = res | (1 << i);
                    c0 = 0;
                }
            }
        }
        return res;
    }
};
