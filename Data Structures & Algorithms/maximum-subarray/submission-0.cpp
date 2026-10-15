class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentSum = 0;
        int maximumSum = nums[0];
        for(auto num: nums){
            currentSum = max(0, currentSum);
            currentSum += num;
            maximumSum = max(maximumSum, currentSum);
        }
        return maximumSum;
    }
};
