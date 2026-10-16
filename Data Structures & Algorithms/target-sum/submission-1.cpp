class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for(auto it: nums){ totalSum += it; }
        dp.assign(nums.size()+1, vector<int>(2*totalSum+1, -1));
        return dfs(nums, target, 0);
    }
private:
    vector<vector<int>> dp;
    int dfs(vector<int>& nums, int target, int index){
        if(index == nums.size()){return target == 0; }
        if(dp[index][target]!=-1){ return dp[index][target]; }
        return dp[index][target] = dfs(nums,target-nums[index], index+1)+dfs(nums, target+nums[index], index+1);
    }
};
