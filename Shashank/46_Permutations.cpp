class Solution {
public:
    vector<vector<int> > res;
    void go(vector<int> nums, int curIdx){
        if(curIdx == nums.size()) return;
        if(curIdx == nums.size()-1)
        res.push_back(nums);
        for(int j = curIdx; j < nums.size();j++){               
            swap(nums[curIdx], nums[j]);     
            go(nums, curIdx + 1);     
            swap(nums[curIdx], nums[j]);     
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {        
        go(nums, 0);             
        return res;
    }
};
