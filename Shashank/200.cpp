class Solution {
public:
    int dx[4]={0,0,1,-1};
    int dy[4]={1,-1,0,0};
    int xmax = 0, ymax = 0;
    void dfs(int x,int y,vector<vector<char>>& grid){  
		if(x < 0 || x >= xmax) return; 
        if(y < 0 || y >= ymax) return; 										        
        if(grid[x][y] == '0') return ;     
        grid[x][y]='0';        
        for(int i = 0; i < 4;i++){
            int nbx = x + dx[i];
            int nby = y + dy[i];            
            dfs(nbx, nby, grid);            
        }        
    }
    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0; 
        xmax = grid.size(), ymax = grid[0].size();        
        for(int i = 0;i < xmax; i++){
            for(int j = 0; j < ymax; j++){
                if(grid[i][j] == '1'){                    
                    cnt++;
                    dfs(i, j, grid);                        
                }                
            }
        }
        return cnt;
    }
};
