class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        dp.resize(n+1, vector<int>(target+1, -1));
        return dfs(n,k,target);
    }
private:
    int dfs(int n, int k, int target){
        if(n==0){return target == 0;}
        if(target < 0){ return 0; }
        if(dp[n][target] != -1){ return dp[n][target]; }
        int count = 0;
        for(int i=1;i<=k;i++){
            count = (count + dfs(n-1,k,target-i)) % mod;
        }
        return dp[n][target] = count;
    }
    vector<vector<int>>dp;
    int mod = pow(10,9)+7;
};
