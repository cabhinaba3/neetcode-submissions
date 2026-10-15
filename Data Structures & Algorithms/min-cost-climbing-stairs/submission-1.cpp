class Solution {
public:
    vector<int> dp;
    int minCostClimbingStairs(vector<int>& cost) {
        dp.resize(cost.size(),-1);
        return std::min(dfs(cost, 0), dfs(cost, 1));
    }
    int dfs(vector<int>& cost, int index){
        if(index >= cost.size()){ return 0; }
        if(dp[index] != -1){ return dp[index]; }
        return dp[index] = cost[index]+std::min(dfs(cost, index+1), dfs(cost,index+2));
    }
};
