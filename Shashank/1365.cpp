class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        int cnt[101] = {0};
        for(int i = 0;i < nums.size();i++){
            cnt[nums[i]]++;
        }
        for(int i = 1; i < 101;i++){
            cnt[i] += cnt[i-1];
        }
        for(int i = 0; i < nums.size();i++){            
            nums[i] = (nums[i])?cnt[nums[i]-1]:0;
        }
        return nums;
    }
};




    
    
    
    
