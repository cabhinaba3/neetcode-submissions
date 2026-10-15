class Solution {
private:
    unordered_map<int,int> dp;
public:
    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(coins, amount);
        return (minCoins >= 1e9)?-1: minCoins;
    }
    int dfs(vector<int>& coins, int amount){
        if(amount == 0){ return 0; }
        if(dp.find(amount)!= dp.end()){ return dp[amount]; }
        int res = INT_MAX;
        for(int coin: coins){
            if(amount - coin >=0){
                int tempRes = dfs(coins, amount-coin);
                if(tempRes != INT_MAX){
                    res = min(res, 1+ tempRes);
                }
            }
        }
        return dp[amount] = res;
    }
};
