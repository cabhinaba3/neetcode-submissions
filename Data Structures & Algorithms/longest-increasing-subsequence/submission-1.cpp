class Solution {
private:
    vector<vector<int>> dp;
public:
    int lengthOfLIS(vector<int>& nums) {
        // int n = nums.size();
        // dp.resize(n, vector<int>(n+1, -1));
        // return dfs(nums, 0, -1);
        vector<int> LIS(nums.size(), 1);
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]< nums[j]){
                    LIS[i] = max(LIS[i], 1+ LIS[j]);
                }
            }
        }
        return *max_element(LIS.begin(), LIS.end());
    }
    // int dfs(vector<int>& nums, int i, int j){
    //     if(i == nums.size()){ return 0; }
    //     if(dp[i][j+1]!=-1) return dp[i][j+1];
    //     int LIS = dfs(nums,i+1,j);
    //     if(j == -1 || nums[j]< nums[i]){
    //         LIS = max(LIS, 1+dfs(nums, i+1,i));
    //     }
    //     return dp[i][j+1]=LIS;
    // }
};
