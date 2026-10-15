class Solution {
public:
    int maxCoins(vector<int>& nums) {
        vector<int> newNums(nums.size()+2, 1);
        for(int i=0;i<nums.size();i++)newNums[i+1]=nums[i];
        dp.assign(newNums.size()+1, vector<int>(newNums.size()+1, -1));
        return dfs(newNums, 1, newNums.size()-2);
    }
private:
    vector<vector<int>> dp;
    int dfs(vector<int>& nums, int leftIndex, int rightIndex){
        // base condition
        if(leftIndex > rightIndex){ return 0; }
        if(dp[leftIndex][rightIndex] != -1){ return dp[leftIndex][rightIndex]; }
        int maxCoins = INT_MIN;
        for(int itr = leftIndex; itr <=rightIndex;itr++){
            int coins = nums[leftIndex-1]* nums[itr]* nums[rightIndex+1];
            coins += dfs(nums, leftIndex, itr-1) + dfs(nums, itr+1, rightIndex);
            maxCoins = max(maxCoins, coins);
        }
        return dp[leftIndex][rightIndex] = maxCoins;
    }
};
