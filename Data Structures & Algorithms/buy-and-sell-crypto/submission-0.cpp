class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int left = 0, right = 1;
        int maxProfitValue = 0;
        while(right < prices.size()){
            if(prices[left] < prices[right]){
                maxProfitValue = max(maxProfitValue, prices[right] - prices[left]);
            }else{
                left = right;
            }
            right+=1;
        }
        return maxProfitValue;
    }
};
