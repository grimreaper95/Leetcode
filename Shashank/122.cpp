class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0) return 0;
        int profit = 0;
        int buy = prices[0];
        int sell = prices[0];
        for(int i = 1; i < prices.size();i++){
            if(prices[i] <= prices[i-1]){
                profit += sell - buy;
                buy = prices[i]; 
                sell = prices[i];
            }
            else{
                sell = prices[i];
            }
        }
        profit += sell - buy;
        return profit;
    }
};
