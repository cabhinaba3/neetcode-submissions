class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;
        for(int num: nums){
            int temp = curMax * num;
            curMax = max(max(num * curMax, num * curMin), num);
            curMin = min(min(temp, num * curMin), num);
            res = max(res, curMax);
        }
        return res;
    }
};
