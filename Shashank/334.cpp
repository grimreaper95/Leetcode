       
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int pref[100010],suff[100010];
        memset(pref, 0, sizeof pref);
        memset(suff, 0, sizeof suff);
        pref[0]=nums[0], suff[nums.size()-1]=nums[nums.size()-1];
        for(int i = 1; i < nums.size();i++){
            pref[i] = min(pref[i-1],nums[i]);
        }
        for(int i = nums.size()-2; i >=0 ;i--){
            suff[i] = max(suff[i+1],nums[i]);
        }
        for(int i = 0; i < nums.size();i++){             
            if(nums[i] > pref[i] && nums[i] < suff[i])
                return true;
        }
        return false;
    }
};


//with O(1) space: A decrease in value is not going to contribute to the final triplet

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a = INT_MAX, b = INT_MAX;        
        for(auto x : nums){
            if(x <= a){
                a = x;
            }
            else if(x <= b){
                b = x;
                                
            }
            else
                return true;
        } 
        return false;
    }
};
