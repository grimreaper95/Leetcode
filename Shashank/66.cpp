class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        for(int i = digits.size()-1; i >= 0;i--){            
            int mod = (digits[i] + carry)%10;
            carry = (digits[i] + carry)/10;
            digits[i] = mod;
        }
        reverse(digits.begin(), digits.end());
        if(carry) digits.push_back(carry);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};


