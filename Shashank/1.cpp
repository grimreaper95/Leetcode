class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //we can either sort or use map(tricky with duplicate values)
        vector<pair<int,int> >v;
        for(int i = 0; i < nums.size();i++) v.push_back({nums[i],i});
        sort(v.begin(), v.end());
        int l = 0, r = v.size()-1;
        while(l < r){
            int sum = v[l].first + v[r].first;
            if( sum > target) r--;
            else if(sum < target) l++;
            else break;
        }        
        vector<int> res; 
        res.push_back(v[l].second);
        res.push_back(v[r].second);
        return res;
    }
};
