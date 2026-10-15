class Solution {
private:
    vector<vector<int>> dp;
public:
    int dfs(vector<int>& nums, int index, int first){
        if(index >= nums.size() || (first == 1 && index == nums.size()-1)){
            return 0;
        }
        if(dp[index][first] !=-1){ return dp[index][first];}
        dp[index][first] = max(dfs(nums, index+1, first), nums[index]+dfs(nums, index+2, first | (index==0?1:0)));
        return dp[index][first];
        // if(index >= nums.size())return 0;
        // if(dp[index]!=-1)return dp[index];
        // if(index == 0){
        //     return dp[index]=max(dfs(nums,index+1, false),nums[index]+dfs(nums, index+2, true));
        // }else if(index<nums.size()-1){
        //     return dp[index]=max(dfs(nums,index+1, first),nums[index]+dfs(nums, index+2, first));
        // }else if(index == nums.size()-1){
        //     if(first == false){
        //         return dp[index]=max(dfs(nums,index+1, false),nums[index]+dfs(nums, index+2, false));
        //     }
        //     else{
        //         return dp[index]=max(dfs(nums,index+1, true),dfs(nums, index+2, true));
        //     }
        // }
        // // printf("Coming here");
        // return 0;
        // // return dp[index];
        // // return dp
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1){return nums[0];}
        dp.resize(nums.size(),vector<int>(2, -1));
        return max(dfs(nums, 0, 0), dfs(nums, 1, 1));
    }
};
