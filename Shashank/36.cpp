class Solution {
public:
    bool validRow(vector<vector<char>>& board, int row){
        bool flag = true;
        bool vis[10];
        memset(vis, false, sizeof vis);
        for(int i = 0; i < 9;i++){
            if(board[row][i] != '.'){
                if(!vis[board[row][i] - '0'])
                    vis[board[row][i] - '0'] = true;
                else
                    flag = false;    
            }            
        }
        return flag;    
    }
    
    bool validCol(vector<vector<char>>& board, int col){
        bool flag = true;
        bool vis[10];
        memset(vis, false, sizeof vis);
        for(int i = 0; i < 9;i++){
            if(board[i][col] != '.'){                             
                if(!vis[board[i][col] - '0'])
                    vis[board[i][col] - '0'] = true;
                else
                    flag = false;
            }
        }
        return flag;    
    }
    bool validGrid(vector<vector<char>>& board, int x, int y){
        bool flag = true;
        bool vis[10];
        memset(vis, false, sizeof vis);
        for(int i = x; i < x + 3;i++){
            for(int j = y; j < y + 3; j++){
                if(board[i][j] != '.'){
                    if(!vis[board[i][j] - '0'])
                        vis[board[i][j] - '0'] = true;
                    else
                        return false;                
                }
            }
        }
        return flag;    
    }


    bool isValidSudoku(vector<vector<char>>& board) {
        bool flag = true;
        for(int i = 0; i < 9;i++){
            flag = flag & validRow(board, i) & validCol(board, i);
        }
        for(int i = 0; i < 9; i+=3){
            for(int j = 0; j < 9; j+= 3){
                flag &= validGrid(board,i,j);
            }
        }
        return flag;
    }
};
