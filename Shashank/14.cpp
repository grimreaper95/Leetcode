class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {        
        int res = 100000;
        string resStr="";
        if(strs.size() == 0) return resStr;
        if(strs.size() == 1) return strs[0];
        for(int i = 0; i < strs.size() - 1;i++){            
            int cnt = 0;
            for(int j = 0; j < min(strs[i].length(), strs[i+1].length());j++){
                if(strs[i][j] == strs[i+1][j])
                    cnt++;
                else break;
            }
            res = min(res, cnt);
        }
        for(int i = 0; i < res; i++) resStr+=strs[0][i];
        return resStr;
    }
};
