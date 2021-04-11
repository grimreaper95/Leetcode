//Bitmasking - easier way
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int> > res;        
        for(int i = 0; i < (1 << nums.size()); i++){
            vector<int> ele;
            for(int j = 0; j < nums.size();j++)
                if(i & (1 << j))
                    ele.push_back(nums[j]);
            res.push_back(ele);
        }
        return res;
    }
};


class Solution {
public:    
    vector<vector<int> >res;
    void go(int idx, vector<int> nums, vector<int> temp){        
        if(idx == nums.size()) {
            res.push_back(temp);     
            return;
        }    
        res.push_back(temp);
        for(int i = idx; i < nums.size(); i++){            
            temp.push_back(nums[i]);                       
            go(i + 1, nums, temp);
            temp.pop_back();
        }                            
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> temp;
        go(0, nums, temp);
        return res;
    }
};
