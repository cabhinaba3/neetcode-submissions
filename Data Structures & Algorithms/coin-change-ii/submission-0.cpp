class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<int>& coins, int index, int amount){
        if(amount == 0){ return 1; }
        if(index >= coins.size()){ return 0; }
        if(dp[index][amount] != -1){ return dp[index][amount]; }
        int result = 0;
        if(amount >= coins[index]){
            result = dfs(coins,index+1, amount);
            result += dfs(coins, index, amount - coins[index]);
        }
        return dp[index][amount] = result;
    }
public:
    int change(int amount, vector<int>& coins) {
        sort(coins.begin(), coins.end());
        dp.assign(coins.size(), vector<int>(amount+1, -1));
        return dfs(coins, 0, amount);
    }
};
