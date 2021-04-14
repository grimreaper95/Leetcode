class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int mat[201][201];
    int dp[201][201];
    int xmax, ymax;
    bool isValid(int x,int y, int val){
        if(x < 0 || y < 0 || x >= xmax || y >= ymax)
            return false;        
        if(mat[x][y] <= val)
            return false;
        return true;
    }
    int go(int x, int y, int prev){                
        if(dp[x][y]) return dp[x][y];
        int ret = 0;
        for(int i = 0; i < 4;i++){
            int nbx = x + dx[i];
            int nby = y + dy[i];               
            if(!isValid(nbx, nby, mat[x][y])) continue;
            ret = max(ret, go(nbx, nby, mat[x][y]) + 1);
        }        
        return (dp[x][y] = ret);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size();i++){
            for(int j = 0; j < matrix[i].size();j++){
                mat[i][j] = matrix[i][j];
            }
        }
        xmax = matrix.size(), ymax = matrix[0].size();
        int res = 0; 
        for(int i = 0; i < xmax;i++)
            for(int j = 0; j < ymax; j++)
                res = max(res, go(i, j, -1) + 1);        
        return res;
    }
};
