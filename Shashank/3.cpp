class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length() <= 1) return s.length();        
        unordered_map<char,bool>alpha;
        int l = 0, r = 1;
        alpha[s[l]]=0;
        int maxi = 1;
        while(r < s.length()){
            if(alpha.find(s[r])==alpha.end()){
                alpha[s[r]] = r;
                maxi = max(maxi, r - l + 1);
            }                
            else{ 
                while(s[l] != s[r]){
                    alpha.erase(s[l]);                    
                    l++;
                }
                alpha.erase(s[l]);
                l++;
                alpha[s[r]] = r;
            }
            r++;            
        }
        return maxi;
    }
};
