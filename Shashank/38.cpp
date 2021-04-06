class Solution {
public:
    string getStr(int n){
        string str="";
        while(n){
            str += n%10 + '0';
            n/=10;
        }
        reverse(str.begin(), str.end());        
        return str;
    }
    
    string getNum(string s){
        string newNum = "";
        int cnt = 1;     
        for(int i = 0; i < s.length() - 1; i++){
            if(s[i] == s[i+1]){
                cnt++;
            }
            else{
                newNum += getStr(cnt) + s[i];
                cnt = 1;
            }
        }
        
        newNum += getStr(cnt) + s[s.length()-1];
        //cout<<newNum<<endl;
        return newNum;
    }
    
    string countAndSay(int n) {
        if(n == 1)
            return "1";
        else{
            string newNum = "1";
            for(int i = 0; i < n - 1;i++){
                newNum = getNum(newNum);    
            }
            return newNum;
        }
    }
};
