class Solution {
private:
    vector<int> dp;
public:
    int climbStairs(int n) {
        dp.resize(n+1, -1);
        return dfs(n, 0);
    }
    int dfs(int n, int index){
        if(index>=n) return index == n;
        if(dp[index] != -1) return dp[index];
        return dp[index] = dfs(n, index+1)+dfs(n, index+2);
    }
};
