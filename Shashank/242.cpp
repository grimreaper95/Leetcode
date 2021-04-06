class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt1[26]={0}, cnt2[26]={0};
        bool flag= true;
        for(int i = 0; i < s.length();i++){
            cnt1[s[i]-'a']++;
        }
        for(int i = 0; i < t.length();i++){
            cnt2[t[i]-'a']++;
        }
        for(int i = 0; i < 26;i++){
            if(cnt1[i] != cnt2[i]){
                flag = false;
                break;
            }
        }
        return flag;
    }
};
