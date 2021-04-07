class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        bool vis[10005] = {0};
        vector<vector<string> >res;           
        int alpha[10005][26];
        memset(alpha, 0, sizeof alpha);
        for(int i = 0;i < strs.size();i++){
            for(int j = 0; j < strs[i].length();j++){
                alpha[i][strs[i][j]-'a']++;
            }
        }
        
        
        int i;
        for(i = 0; i < strs.size()-1;i++){
            vector<string> temp_res;            
            if(vis[i]) continue; 
            temp_res.push_back(strs[i]);            
            vis[i]=true;
            for(int j = i + 1; j < strs.size();j++){
                if(vis[j]) continue;                               
                bool flag = true;
                for(int k = 0; k < 26; k++){
                    if(alpha[i][k] != alpha[j][k]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    temp_res.push_back(strs[j]);
                    vis[j] = true;
                }    
            }
            res.push_back(temp_res);            
        }
        if(!vis[i]){
            vector<string> temp; temp.push_back(strs[i]);
            res.push_back(temp);
        }
        return res;
    }
};
