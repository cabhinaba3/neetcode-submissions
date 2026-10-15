class Solution {
private:
    // memoisation
    vector<int> dp;
    int dfs(vector<int>& nums, int index){
        if(index>=nums.size()){
            // out of bound conditon
            return 0;
        }
        // if we got the previously calculated value
        if(dp[index]!=-1){
            return dp[index];
        }
        dp[index] = max(dfs(nums, index+1), nums[index]+dfs(nums, index+2));
        return dp[index];
    }
public:
    int rob(vector<int>& nums) {
        dp.resize(nums.size(),-1);
        return dfs(nums, 0);
    }
};
