class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<int>& prices, int index, int buying){
        if(index >= prices.size()){ return 0; }
        if(dp[index][buying]!=-1){ return dp[index][buying]; }
        int doNothing = dfs(prices, index+1, buying);
        int doSomething;
        if(buying){
            doSomething = dfs(prices,index+1, 0) - prices[index];
        }else{
            doSomething = dfs(prices, index+2,1)+prices[index];
        }
        return dp[index][buying] = max(doNothing, doSomething);
    }
public:
    int maxProfit(vector<int>& prices) {
        dp.assign(prices.size(),vector<int>(2,-1));
        return dfs(prices, 0, 1);
    }
};
