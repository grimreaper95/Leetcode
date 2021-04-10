class Solution {
public:
    vector<string> res;
    vector<string> code;
    void go(int curIdx, string str){  
        if(curIdx == code.size()){            
            res.push_back(str);            
            return;  
        } 
        for(int i = 0; i < code[curIdx].length();i++){
            str += code[curIdx][i];
            go(curIdx + 1, str);
            str.erase(str.length()-1);
        }
        return ;
    }
    vector<string> letterCombinations(string digits) {        
        if(!digits.size()) return res;
        unordered_map<int, string> mp;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";               
        for(int i = 0; i < digits.length();i++){            
            string str = mp[digits[i]-'0'];
            code.push_back(str);                      
        }
        go(0,"");        
        return res;
    }
};
