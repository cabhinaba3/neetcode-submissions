class Solution {
private:
    int maxProfit = INT_MIN;
    vector<int> dp;
    int dfs(vector<int>& nums, int profit, int index){
        // two options
        // choose to rob that index if yes: cannot trob the next one
        // if no can choose to rob the next one
        if(index>=nums.size()){ 
            return 0;
            // maxProfit = max(maxProfit, profit);
            // return; 
        }
        if(dp[index]!=-1) return dp[index];
        // lets say I choose to rob that house
        return dp[index]=max(dfs(nums, profit, index+1),nums[index]+dfs(nums, profit, index+2));
    }
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return dfs(nums, 0,0);
        // return maxProfit;
    }
};
