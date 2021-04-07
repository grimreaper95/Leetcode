class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
        unordered_map<int,int> mp;
        vector<vector<int>> res;
        if(nums.size() < 3) return res;
        map<pair<int,int>, bool> vis;        
        for(int i = 0; i < nums.size();i++) mp[nums[i]]=i;
        for(int i = 0; i < nums.size() - 1;i++){
            for(int j = i + 1; j < nums.size(); j++){
                int k = -1 * (nums[i] + nums[j]);                
                if(mp[k] && mp[k]!=i && mp[k]!=j){
                    if(!vis[{nums[i],nums[j]}] && !vis[{nums[j],nums[i]}] && !vis[{nums[i],k}] 
                       && !vis[{k,nums[i]}]){
                        vis[{nums[i],nums[j]}] = true;
                        vis[{nums[j],nums[i]}] = true;
                        vis[{nums[i], k}] = true;
                        vis[{k, nums[i]}] = true;
                        res.push_back(vector<int>{nums[i], nums[j], k});  
                    }                    
                }
            }
        }        
        //1,3,-4,1,-4,8
        if(res.size()==0) return res;
        return res;
    }
};

/*with sorting --- why didn't I sort!!!*/
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
        unordered_map<int,int> mp;
        vector<vector<int>> res;     
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size();i++) mp[nums[i]]=i;
        for(int i = 0; i < nums.size();i++){
            if(i > 0 && nums[i] == nums[i-1])
                continue;
            for(int j = i + 1; j < nums.size();j++){
                if(j > i + 1 && nums[j] == nums[j-1]) 
                    continue;
                int k = -nums[i] -nums[j];
                if(mp[k] && mp[k] > j)
                    res.emplace_back(vector<int>{nums[i],nums[j],k});
            }
        }
        return res;
    }
};
