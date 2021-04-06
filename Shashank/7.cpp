class Solution {
public:
    int reverse(int x) {
        long long d = 0;
        while(x){
            d = d * 10 + x%10;
            x = x/10;
        } 
        if(d > ((long long)pow(2,31)-1) || d < (long long)pow(-2,31)){
            return 0;
        }
        return d;
    }
};

