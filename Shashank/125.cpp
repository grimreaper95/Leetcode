class Solution {
public:
    bool ispalin(string s){
        for(int i = 0; i < s.length()/2;i++){
            if(s[i] != s[s.length()-i-1]){
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
        string str = "";
        for(int i = 0; i < s.length();i++){
            if((s[i]>='a' && s[i] <='z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')){
                if(s[i] >= 'A' && s[i] <='Z'){                                
                    s[i] = s[i] + 32;
                }
                str += s[i];
            }
        }     
        return ispalin(str);
    }
};
