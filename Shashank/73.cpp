class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {        
        bool row0 = false, col0 = false;
        //fist row, first column to act as flags
        for(int i = 0; i < matrix[0].size();i++) {
            if(!matrix[0][i]) row0 = true;
        }
        for(int i = 0; i < matrix.size();i++) {
            if(!matrix[i][0]) col0 = true;
        }
        //using fist row, first column as flags
        for(int i = 1; i < matrix.size();i++){
            for(int j = 1; j < matrix[i].size();j++){
                if(!matrix[i][j]) {                    
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }        
        //marking flags
        for(int i = 1; i < matrix.size();i++){
            if(!matrix[i][0]){        
                for(int j = 1; j < matrix[i].size();j++) matrix[i][j]=0;
            }
        }
        for(int i = 1; i < matrix[0].size();i++){
            if(!matrix[0][i]){
                for(int j = 1; j < matrix.size();j++) matrix[j][i]=0;
            }
        }
        //fist row, first column
        if(row0) for(int i = 0; i < matrix[0].size();i++) matrix[0][i]=0;
        if(col0) for(int i = 0; i < matrix.size();i++) matrix[i][0]=0;
        
    }
};
