class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> newNums(nums.size()+2, 1);
        for(int i=0;i<nums.size();i++)newNums[i+1] = nums[i];
        dp.assign(nums.size()+2, vector<int>(nums.size()+2, -1));
        return dfs(newNums, 1, newNums.size()-2);
    }
private:
    vector<vector<int>> dp;
    int dfs(vector<int>& nums, int leftIndex, int rightIndex){
        if(leftIndex > rightIndex){ return 0; }
        // if(nums.size() == 2){ return 0; }
        if(dp[leftIndex][rightIndex]!=-1){ return dp[leftIndex][rightIndex]; }
        int maxCoins = 0;
        for(int i=leftIndex;i<=rightIndex;i++){
            int coins = nums[leftIndex-1]* nums[i]* nums[rightIndex+1];
            // vector<int> newNums{nums};
            // newNums.erase(newNums.begin()+i);
            coins += dfs(nums, leftIndex, i-1)+ dfs(nums, i+1, rightIndex);
            maxCoins = max(maxCoins, coins);
        }
        return dp[leftIndex][rightIndex] = maxCoins;
    }
};
