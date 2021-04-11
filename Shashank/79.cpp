class Solution {
public:
    int xmax, ymax;
    vector<vector<char> > mat;
    bool found = true;
    string word;
    bool vis[6][6];
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    bool isValid(int x, int y, int idx){
        if(x < 0 || x >= xmax || y < 0 || y >= ymax)
            return false;
        if(vis[x][y])
            return false;
        if(mat[x][y] != word[idx])
            return false;
        return true;
    }
    
    bool dfs(int x, int y, int curIdx){           
        vis[x][y] = true;
        if(curIdx == word.length()-1)
            return true;
        bool ret = false;
        for(int i = 0; i < 4;i++){
            int nbx = x + dx[i];
            int nby = y + dy[i];
            if(isValid(nbx, nby, curIdx + 1))
                ret = ret || dfs(nbx, nby, curIdx + 1);
        }
        vis[x][y] = false; 
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        this->word =  word;        
        xmax = board.size(), ymax = board[0].size();
        if(word.length() > xmax * ymax) return false;
        for(int i = 0; i < board.size();i++){
            mat.push_back(board[i]);
        }
        bool res = false;
        for(int i = 0; i < board.size();i++){
            for(int j = 0; j < board[i].size();j++){
                if(isValid(i, j, 0)){                    
                    res = res | dfs(i, j, 0);                    
                    if(res) break;
                    memset(vis, false, sizeof vis);                    
                }                    
            }
        }
        return res;
    }
};
