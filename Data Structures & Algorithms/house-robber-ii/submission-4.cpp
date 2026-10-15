class Solution {
private:
    vector<vector<int>> dp;
    int dfs(vector<int>& nums, int index, int first){
        // base conditions
        if(index >= nums.size()){ return 0; }
        if(index == nums.size()-1 && first==1){ return 0; }
        // check for previously calculated values
        if(dp[index][first]!=-1)return dp[index][first];
        // we need to calculate
        dp[index][first] = max(dfs(nums, index+1, first), nums[index]+dfs(nums, index+2, first));
        return dp[index][first];
    }
public:
    int rob(vector<int>& nums) {
        if(nums.size()==1)return nums[0];
        // -1 mean we havent calculated that cell
        dp.resize(nums.size(), vector<int>(2,-1));
        return max(dfs(nums,0, 1), dfs(nums, 1, 0));
    }
};
