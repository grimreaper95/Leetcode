class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int res = 1;
        pair<int,int> res_pair;
        res_pair={0,0};
        for(int i = 0; i < n;i++){
            int lo = i - 1;
            int ro = i + 1;
            while(lo >= 0 && ro <=n && s[lo] == s[ro]){
                if(res < ro - lo + 1){
                    res = ro - lo + 1;
                    res_pair = {lo,ro};
                }                
                lo--,ro++;
            }
            int le = i;
            int re = i + 1;
            while(le >= 0 && re <=n && s[le] == s[re]){
                if(res < re - le + 1){
                    res = re - le + 1;
                    res_pair = {le,re};
                }                
                le--,re++;
            }
        }
        string res_str;
        for(int i = res_pair.first; i <= res_pair.second; i++){
            res_str += s[i];
        }
        return res_str;
    }
};
