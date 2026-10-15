class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum = 0;
        for (int x : nums) totalSum += x;

        int n = nums.size();
        offset = totalSum;

        // target range: [-totalSum, +totalSum]
        dp.assign(n, vector<int>(2 * totalSum + 1, INT_MIN));

        return dfs(nums, 0, target);
    }

private:
    vector<vector<int>> dp;
    int offset;

    int dfs(vector<int>& nums, int index, int target) {
        // invalid target → no ways
        if (target < -offset || target > offset) return 0;

        if (index == nums.size())
            return target == 0 ? 1 : 0;

        int &res = dp[index][target + offset];
        if (res != INT_MIN) return res;

        res =
            dfs(nums, index + 1, target - nums[index]) +
            dfs(nums, index + 1, target + nums[index]);

        return res;
    }
};
