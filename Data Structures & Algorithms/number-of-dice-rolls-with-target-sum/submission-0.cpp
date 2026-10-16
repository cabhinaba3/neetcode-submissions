class Solution {
private:
    int mod = pow(10,9)+7;
    vector<vector<int>> dp;
    int dfs(int n, int k, int target, int index, int value){
        // if(index >= n)return 0;
        if(index == n){
            if(target == value){ return 1;}
            return 0;
        }
        if(value > target){ return 0; }
        if(dp[index][value] != -1){ return dp[index][value]; }
        int count = 0;
        for(int i=1;i<=k;i++){
            count = (count + dfs(n,k,target, index+1, value+i)) % mod;
        }
        return dp[index][value] = count;
    }
public:
    int numRollsToTarget(int n, int k, int target) {
        dp.assign(n+1, vector<int>(target+1, -1));
        return dfs(n,k,target, 0, 0);
    }
};
